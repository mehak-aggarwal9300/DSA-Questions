#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *ptr;
}*front, *rear;

typedef struct node nd;

void traverse()
{
    nd *tmp;
    if(front==NULL)
    {
        printf("Empty");
        return;
    }

    for(tmp=front;tmp->ptr!=front;tmp=tmp->ptr)
    {
        printf("%d ",tmp->val);
    }
    printf("%d ",tmp->val);
}

void insert()
{
    nd *n;
    n=(nd*) malloc(sizeof(nd));

    if(n==NULL)
    {
        printf("Allocation failed");    //generally valid for all allocation
        return;
    }

    n->ptr=NULL;
    scanf("%d",&n->val);

    if(front==NULL) 
    {   front=rear=n;
        n->ptr=n;   //!!
    }
    else 
    {
        n->ptr=rear->ptr;
        rear->ptr=n;
        rear=n;
    }
}


int del()
{
    nd *tmp;
    int a;

    if(front==NULL)
    {
        printf("Empty Queue");
        return -1;
    }

    tmp=front;
    a=tmp->val;

    if(front==rear) front=rear=NULL; //one element
    else 
    {
        rear->ptr=front->ptr;
        front=front->ptr;
    }

    free(tmp);
    return a;
}


void main()
{
    int ch,ele;
    front=rear=NULL;
    
    do
    {
    printf("1. insert   2. delete   3. display   4. exit");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1: insert();
            break;
    case 2: ele = del();
            if(ele!=-1)
            printf("%d is deleted", ele);
            break;
    case 3: traverse();
            break;
    
    default:break;
    }

    } while (ch!=4);
}