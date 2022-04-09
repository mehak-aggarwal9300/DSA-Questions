#include<stdio.h>
#define MAX 11

int Q[MAX],front, rear;

//in queues using arrays implementation, 
//we cannot re-use a place once element is deleted, 
//since front always gets ++

void traverse()
{
    if(front==-1)
    {
        printf("Empty list");
        return;
    }

    for(int i=front;i<=rear;i++)
    {
        printf("%d ",Q[i]);
    }

}


void insert(int ele)
{
    if(rear==MAX-1)
    {
        printf("Queue full!");
        return;
    }

    if(front==-1)
    {
        front++;
    }
    rear++;
    Q[rear]=ele;
}

int del()
{
    int tmp=-1;
    if(front==-1)
    {
        printf("Empty queue");
    }

    tmp=Q[front];
    Q[front]=0;
    if(front==rear)
    {
        front=rear=-1;
    }
    else front++;
    return tmp;
}

int main()
{   int ch=0,ele;
    front=rear=-1;
    do
    {
        traverse();   
        printf("\n"); 
        printf("1. enqueue  2. dequeue   3. traverse   4. exit");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: printf("Enter element:");
                scanf("%d",&ele);
                insert(ele);
                break;
        case 2: ele = del();
                if(ele!=-1)
                printf("%d is deleted\n", ele);
                break;
        case 3: traverse();
                break;

        default:break;
    }

    }while (ch!=4);
    
}


