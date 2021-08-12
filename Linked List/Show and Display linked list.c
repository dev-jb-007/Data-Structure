//
//  Show and Display linked list.c
//  Linked List
//
//  Created by Work on 25/06/21.
//

#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
    int data;
    struct node * next;
}*first=NULL;
void create(int n)
{   struct node *t,*last;
//    We may think that the use of first here is unnecesary but we need to specify a starting point as a refrence to store data
    printf("Start entering elements:\n");
    first=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&first->data);
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&t->data);
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void recursiveDisplay(struct node *p)
{
    if(p)
    {
//        recursiveDisplay(p->next); It will print in descending order
        printf("%d ",p->data);
        recursiveDisplay(p->next); //It will print the data in ascending order as it will call it at calling time
    }
}
int count(struct node *p){
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}
int sum(struct node *p)
{
    int c=0;
    while(p)
    {
        c+=p->data;
        p=p->next;
    }
    return c;
}
int max(struct node *p)
{
    int max=INT_MIN;
    while(p)
    {
        if(p->data>max)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}
struct node * linearsearch(struct node *p,int element)
{
    while(p)
    {
        if(p->data==element)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
struct node * recursivelinearsearch(struct node *p,int element)
{
    if(p==NULL)
        return NULL;
    if(p->data==element)
        return p;
    return recursivelinearsearch(p->next,element);
    
}
void improvedLinearSearch(struct node *p,int key)
{   struct node *q=NULL;
    while(p)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
        }
        q=p;
        p=p->next;
    }
}
void insert(struct node *p,int index)
{
    struct node *t=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the element to be inserted:");
    scanf("%d",&t->data);
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else{
        for (int i=1; (i<index) && p; i++) {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
int main(){
    int n;
    printf("Enter the total number of elements:");
    scanf("%d",&n);
    create(n);
    recursiveDisplay(first);
    printf("\n");
    insert(first,10);
    recursiveDisplay(first);
//    struct node *p=recursivelinearsearch(first, 4);
//    printf("\n%d",max(first));
//    struct node *p=linearsearch(first, 4);
//    improvedLinearSearch(first, 4);
//    recursiveDisplay(first);
//    printf("\n%d",p->data);
    return 0;
}
