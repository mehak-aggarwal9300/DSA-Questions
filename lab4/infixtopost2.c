
//errors hia ismei

#include <stdio.h>
#include <string.h>
#include<stdlib.h>


typedef struct Stack
{
    char val[2];    //char* val not here
    struct Stack *ptr;
}st;

st *tos;

void push(char* newv )  //changed "val" to "newv"
{
    st *n;
    n = (st*)malloc(sizeof(st));
    strcpy(n->val,newv);  
    n->ptr = NULL;
    if(tos!=NULL) n->ptr=tos;
    tos=n;

    // printf("pushed: %s",n->val);
    // if(tos->ptr) printf("tos ptr: %s",tos->ptr->val);
}

char* pop(char elem[])
{
    // char *elem;
    st *temp2;
    if(tos==NULL)
    {
        printf("Empty stack");
        return "-";
    }
    elem=tos->val;  
    //strcpy not working if elem is ptr and val[2]
    //normal allocation not working when both [2]
    printf(elem);
    temp2=tos;
    tos=tos->ptr;
    free(temp2);
    return elem;
}

char* top()
{
    char *elem;
    st *n;
    if(tos==NULL)
    {
        printf("Empty stack");
        return "-";
    }

    strcpy(elem,tos->val);
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
    // printf(tos->ptr->val);
    for (tmp=tos;tmp!=NULL;tmp=tmp->ptr)
    {

        printf(" %s ", tmp->val);
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

// void topostfix(char* exp)
// {
//     char output[20];
//     for(int i=0;i<strlen(exp);i++)
//     {   
//         char *ch;
//         strcpy(ch,exp[i]);
//         if(ch>='0'&&ch<='9')
//         {
//             strncat(output,ch,1);
//         }else if(ch=='(')
//         {
//             push(ch);
//         }else if(ch==')')
//         {
//             while(top()!='(')
//             {
//                strncat(output,pop(),1);
//             }
//         }
//         else
//         {
//             while(!isempty()&&top()!='('&&getpriority(top())>=getpriority(ch))  //size>0
//             {
//                 strncat(output,pop(),1);
//             }
//             push(ch);
//         }

//     }
//     printf("post: %s",output);

// }

int main()
{
    push("A");
    push("B");
    push("C");
    
    traverse();
    char p[2];
    printf("%s",pop(p));
    printf("\n");
    // printf(top());


}
