#include<stdio.h>
#define MAX 11

int Q[MAX],front,rear;

void traverse()
{
    int i;
    if(front==-1)
    {
        printf("Empty list");
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",Q[i]);
    }
    if(rear<front)
    {
        for(i=front;i<MAX-1;i++)
            printf("%d",Q[i]);

        for(i=0;i<=rear;i++)
            printf("%d",Q[i]);
    }

}


void insert()
{
    if((front==0&&rear==MAX-1)||(front==rear+1))
    {
        printf("Queue full!");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    if(rear==MAX-1)
    {
        rear=0;
    }
    else rear++;
    scanf("%d",&Q[rear]);
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
    else if(front==MAX-1)
    {
        front=0;
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
        case 1: insert();
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


