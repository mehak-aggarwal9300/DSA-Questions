#include<stdio.h>
#include<stdlib.h>

typedef struct pnode
{
    int coef;
    int power;
    struct pnode* next;
}Pnode;

void create(Pnode** poly)
{
    int coef, exp, ch;
    Pnode* temp = (Pnode*)malloc(sizeof(Pnode));
    *poly = temp;
    do{
        printf("\n Coeffecient: ");
        scanf("%d", &coef);
        printf("\n Exponent: ");
        scanf("%d", &exp);
        temp->coef = coef;
        temp->power = exp;
        temp-> next = NULL;
        printf("\nHave more terms? (Type 1 for yes) : ");
        scanf("%d", &ch);
        if(ch)
        {
            temp->next = (Pnode*)malloc(sizeof(Pnode));
            temp = temp->next;
            temp->next = NULL;
        }
    }while(ch);   
}

void traverse(char str[], Pnode* p)
{
    Pnode *tmp;
    printf("%s Polynomial is:",str);

    tmp=p;

    while(tmp!=NULL)
    {
        printf(" %d",tmp->coef);
        printf("x^%d",tmp->power);
        if(tmp->next!=NULL)
        printf("+");
        
        tmp=tmp->next;
    }

    return;
}

void addPolynomials(Pnode** result, Pnode* first, Pnode* second)
{
    Pnode* temp = (Pnode*)malloc(sizeof(Pnode));
    temp->next = NULL;
    *result = temp;
    while(first && second)
    {
        if(first->power > second->power)
        {
            temp->coef = first->coef;
            temp->power = first->power;
            first = first->next;
        }
        else if(first->power < second->power)
        {
            temp->coef = second->coef;
            temp->power = second->power;
            second = second->next;
        }
        else
        {
            temp->coef = first->coef + second->coef;
            temp->power = first->power;
            first = first->next;
            second = second->next;
        }

        if(first && second)
        {
            temp->next = (Pnode*)malloc(sizeof(Pnode));
            temp = temp->next;
            temp->next = NULL;
        }
    }
    while(first || second)
    {
        temp->next = (Pnode*)malloc(sizeof(Pnode));
        temp = temp->next;
        temp->next = NULL;
            
        if(first)
        {
            temp->coef = first->coef;
            temp->power = first->power;
            first = first->next;
        }

        else if(second)
        {
            temp->coef = second->coef;
            temp->power = second->power;
            second = second->next;
        }
    }
}
int main()
{
    Pnode* first = NULL;
    Pnode* second = NULL;
    Pnode* result = NULL;

    printf("\nFirst polynomial:\n");
    create(&first);
    traverse("first",first);
    printf("\nSecond polynomial:\n");
    create(&second);
    traverse("second",second);
    addPolynomials(&result, first, second);
    traverse("resulted",result);
    return 0;
} 
