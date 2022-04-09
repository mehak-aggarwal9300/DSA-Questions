#include<stdio.h>
#include<stdlib.h>

typedef struct pnode
{
    int coeff;
    int expo;
    struct pnode *ptr;
}Pnode;



Pnode *create()
{
    Pnode *p,*cptr,*prev;
    char ch='Y';
    p=(Pnode*)malloc(sizeof(Pnode));

    printf("Enter 1st term coef and exp");
    scanf("%d %d",&cptr->coeff,&cptr->expo);
    prev=p;

    printf("Are there more terms(Y/N)?");
    scanf("%c",&ch);

    while(ch=='Y')
    {
        cptr = (Pnode*)malloc(sizeof(Pnode));
        printf("Enter next term coef and exp");
        scanf("%d %d",&cptr->coeff,&cptr->expo);
        prev->ptr = cptr;
        prev=cptr;

        printf("Press 'Y' for more terms.");
        scanf("%c",&ch);

    }
    
    prev->ptr=NULL;
    return p;   //return first element
}

void traverse(Pnode* p)
{
    Pnode *tmp;
    printf("Polynomial is:");

    tmp=p;

    while(tmp!=NULL)
    {
        printf(" %d",tmp->coeff);
        printf("x^%d",tmp->expo);
        if(tmp->ptr!=NULL)
        printf("+");
        
        tmp=tmp->ptr;
    }

    return;
}

void add_poly(Pnode *p1,Pnode *p2)
{
    Pnode *p3,*cptr, *tmp;
    tmp = (Pnode*) malloc(sizeof(Pnode));
    p3=tmp;
    if(p1->expo>p2->expo)
    {
        tmp->coeff=p1->coeff;
        tmp->expo=p1->expo;
        p1=p1->ptr;
    }
    else if(p2->expo>p1->expo)
    {
        tmp->coeff=p2->coeff;
        tmp->expo=p2->expo;
        p2=p2->ptr;
    }

    else
    {
        tmp->coeff=p1->coeff+p2->coeff;
        tmp->expo=p1->expo;
        p1=p1->ptr;
        p2=p2->ptr;
    }

}


int main()
{
    Pnode *p1=create();
    Pnode *p2=create();
    traverse(p1);
    printf("\n");
    traverse(p2);
    return 0;
}

