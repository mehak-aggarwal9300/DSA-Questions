#define SIZE 100
#include<stdio.h>
void push(int n);
int pop();
void display();
int stack[SIZE];
int tos;

int main()
{   int ch=0,ele;
    tos=-1;
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
    case 3: display();
            break;
    
    default:break;
    }

    } while (ch!=4);
    
}

void push(int n){
    if(tos>=(SIZE-1))
    {
        printf("Overflow");
        return;
    }

    tos++;
    stack[tos]=n;
}

int pop(){
    if(tos==-1){
        printf("Empty Stack");
        return -1;
    }
    int i= stack[tos];
    stack[tos]=0;
    tos--;
    return i;
}

void display(){
    if(tos==-1){
        printf("Empty stack");
        return;
    }
    int i=tos;
    while (i>=0)
    {
        printf("   %d \n|      |\n",stack[i]);
        i--;
    }
    
}