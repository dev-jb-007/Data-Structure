#include<stdio.h>
#include<stdlib.h>
int *pair(int n,int m,int A[n],int B[m],int x)
{
    int *c=(int *)malloc(2*sizeof(int));
    int i=n-1;
    int j=m-1;
    while(A[i]+B[j]>x&&i>=0&&j>=0)
    {
        if(A[i]<B[j])
        {
            j--;
        }
        else{
            i--;
        }
    }
    if(i<0)
    {
        c[0]=A[i+1];
        c[1]=A[j];
    }
    else if(j<0)
    {
        c[1]=A[j+1];
        c[0]=A[i];
    }
    else{
        c[0]=A[i];
        c[1]=B[j];
    }
    return c;
}
int main(){
    int A[]={2,16,32,55};
    int B[]={88,89,90,91};
    int *c=pair(4,4,A,B,100);
    printf("%d %d",c[0],c[1]);
}
