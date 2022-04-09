#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node *ptr;
}nd;

nd *tos;

void push(int val)
{
    nd *n;
    n = (nd*)malloc(sizeof(nd));
    n->val=val;
    n->ptr = NULL;
    if(tos!=NULL) n->ptr=tos;
    tos=n;
}

int pop(){
    int ele;
    nd* n;
    if(tos==NULL)
    {
        printf("Empty stack");
        return -1;
    }

    ele=tos->val;
    n=tos;
    tos=tos->ptr;
    free(n);
    return ele;
}

void traverse()
{
    nd *tmp;
    if(tos==NULL)
    {
        printf("Empty Stack");
        return;
    }

    for (tmp=tos;tmp!=NULL;tmp=tmp->ptr)
    {
     printf(" %d", tmp->val);
    }
    
}


int main()
{   int ch,ele;
    do
    {
    printf("1. push 2.pop   3.display   4. exit");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1: printf("Enter element:");
            scanf("%d",&ele);
            push(ele);
            break;
    case 2: ele = pop();
            if(ele!=-1)
            printf("%d is deleted", ele);
            break;
    case 3: traverse();
            break;
    
    default:break;
    }

    } while (ch!=4);
    
}