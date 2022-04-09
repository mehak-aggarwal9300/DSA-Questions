#include <stdio.h>
#include <string.h>
#include<stdlib.h>


typedef struct Stack
{
    char val;    
    struct Stack *ptr;
}st;

st *tos;

void push(char v)  
{
    st *n;
    n = (st*)malloc(sizeof(st));
    n->val=v;  
    n->ptr = NULL;
    if(tos!=NULL) n->ptr=tos;
    tos=n;

}

char pop()
{
    char elem;
    st *temp2;
    if(tos==NULL)
    {
        printf("Empty stack");
        return '-';
    }
    elem=tos->val;  
    temp2=tos;
    tos=tos->ptr;
    free(temp2);
    return elem;
}

char top()
{
    char elem;
    st *n;
    if(tos==NULL)
    {
        printf("Empty stack");
        return '-';
    }

    elem=tos->val;
    return elem;
}

void traverse()
{
    st *tmp;
    if(tos==NULL)
    {
        printf("Empty Stack");
        return;
    }
    for (tmp=tos;tmp!=NULL;tmp=tmp->ptr)
    {

        printf(" %c ", tmp->val);
    }
    
}

int getpriority(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 1;
        case '/':
        case '%':
        case '*':return 2;
        case '^':return 3;
    }
    return 0;
}

int isempty()
{
    if(tos==NULL) return -1;
}

void topostfix(char exp[])
{
    char output[20];
       int index=0;
    for(int i=0;i<strlen(exp);i++)
    {   
        char ch;
        ch=exp[i];
        if(ch>='0'&&ch<='9')
        {
            output[index++]=ch;
        }else if(ch=='(')
        {
            push(ch);
        }else if(ch==')')
        {
            while(top()!='(')
            {
               output[index++]=pop();        
            }
        }
        else
        {
            while(!isempty()&&top()!='('&&getpriority(top())>=getpriority(ch))
            {   
               char c=pop();
               printf("agya");
               output[index++]=c;        
            }
            push(ch);
        }

    }
    printf("post: %s",output);

}

int main()
{
    topostfix("((2+3)*(4-5)/6-2)");
}
