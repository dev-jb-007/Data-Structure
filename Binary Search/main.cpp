//
//  main.cpp
//  Binary Search
//
//  Created by Work on 26/06/21.
//

#include <iostream>
int binarysearch(int low,int high,int A[],int element)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(A[mid]==mid)
        {
            return A[low];
        }
        else if(element>A[mid])
        {
            return binarysearch(mid+1, high, A,element);
//            low=mid+1;
        }
        else{
//            high=mid-1;
            return binarysearch(low, mid-1, A,element);
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int A[]={1,4,8,12,14,15};
    printf("%d",binarysearch(0, 5, A,13));
    return 0;
}
