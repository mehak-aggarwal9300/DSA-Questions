#include<stdio.h>
#include<stdlib.h>


// we can typedef struct node to node, then every struct node will be replaced by node.

struct node
{   int val;
    struct node *ptr;
}*first;

struct node* create_node()
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node)); 
    return p;
}

void print()
{
  struct node *tmp;
  if(first==NULL){
      printf("Empty list");
      return;
  }  

  for(tmp=first;tmp!=NULL;tmp=tmp->ptr)
  {
      printf("%d ",tmp->val);
  }
}

//INSERTION
void ins_beg(){
    struct node *n;
    // n = (struct node*)malloc(sizeof(struct node));  //create new node
    printf("\nenter ele to be inserted:");
    n= create_node();
    scanf("%d", &n->val);   //input
    n->ptr=first;
    first=n;
}

void ins_end(){
    
    struct node *n, *last;
    n = create_node();
    printf("\nenter ele to be inserted:");
    scanf("%d", &n->val);   //input
    n->ptr=NULL;    //point it to null

    if(first==NULL){    //empty list
        first=n;  
        return;  
    }

    for(last=first;last->ptr!=NULL;last=last->ptr);
    last->ptr=n;
}

void ins_ele(int ele){  //check
    // to insert after the element
    struct node *n, *tmp;

    if(first==NULL){
        printf("Empty list");
        return;
    }

    for(tmp=first;((tmp->val!=ele)&&(tmp->ptr!=NULL));tmp=tmp->ptr);

    if((tmp->ptr==NULL)&&(tmp->val!=ele)){
        printf("Element not found");
        return;
    } 

    n = create_node();
    scanf("%d", &n->val);   //input
    n->ptr=NULL;    //point it to null //need?
    n->ptr=tmp->ptr;
    tmp->ptr=n;
}


//DELETION
void del_beg()
{   
    struct node *tmp;
    if(first==NULL){ 
        printf("empty list!"); 
        return;
    }
    tmp=first;
    first=first->ptr;
    free(tmp);
}

void del_end(){
    
    struct node *last,*prev;
    if(first==NULL){ 
        printf("empty list!"); 
        return;
    }
    for(last=first;last->ptr!=NULL;last=last->ptr){
        prev=last;
    }
    prev->ptr=NULL;
    free(last);       
}

void del_ele(int ele){
    struct node *tmp,*prev;
    if(first==NULL){ 
        printf("empty list!"); 
        return;
    }
    for(tmp=first;((tmp->val!=ele)&&(tmp->ptr!=NULL));tmp=tmp->ptr){
        prev=tmp;
    }
    if((tmp->ptr==NULL)&&(tmp->val!=ele)){  //different thoda
        printf("Element not found\n");
        return;
    }
    if(tmp==first){
            if(first->ptr==NULL)    //only 1 element
            {
                first=NULL;
                free(tmp);
                return;
            }
                first=first->ptr;   //del_beg
                free(tmp);
                return;
    }
    prev->ptr=tmp->ptr;
    free(tmp);
    // return;
}

void printReverse(struct node *first)
{
    if (first->ptr == NULL)
    {    printf("%d  ",first->val);
        return;
    }
    printReverse(first->ptr);

    // After everything else is printed, print head
    printf("%d  ",first->val);
}

struct node* reverse(struct node *first)
{
    if ((first==NULL)||(first->ptr == NULL))
    {   
        return first;
    }

    struct node *curr = first;
    struct node *prev = NULL;
    struct node *forward;
    while(curr!=NULL)
    {
        forward = curr->ptr;
        curr->ptr=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

void palindrome(struct node *first)
{
    if((first==NULL)||(first->ptr == NULL))
    {
        //0 or 1 elements
    }
    struct node *A,*B;
    A=first;
    B=first;
    while((B->ptr!=NULL)&&(B->ptr->ptr!=NULL))  //here keeping b->ptr first was also important, since if it doesn't exit there is no b->ptr->ptr
    {   
        A=A->ptr;
        B=B->ptr->ptr;
    }
    struct node *newf=A->ptr;
    A->ptr=NULL;
    newf=reverse(newf);

    struct node *c1=first;
    struct node *c2=newf;
    

    while( c1!=NULL && c2!=NULL)
    {
        
    }
    
}

void mid_node(struct  node *first)
{
    //time - o(n)  not o(n/2) because all the nodes are visited b->ptr->ptr se bhi
    // space - o(1)
    if ((first==NULL)||(first->ptr == NULL))
    {    printf("%d  ",first->val);
        return;
    }
    struct node *A,*B;
    A=first;
    B=first;
    while((B->ptr!=NULL)&&(B->ptr->ptr!=NULL))  //here keeping b->ptr first was also important, since if it doesn't exit there is no b->ptr->ptr
    {   
        A=A->ptr;
        B=B->ptr->ptr;
    }
    printf("Mid node has value %d:",A->val);

}

int main(){
    // printf("ins_end(enter 6 elements in linked list): ");
    // ins_end(); ins_end(); ins_end(); ins_end(); ins_end(); ins_end(); //ins_end();
    
    // int ch,ele;
    // do
    // {
    // printf("1. insert beg   2. insert end   3.insert ele \n");
    // printf("4. delete beg   5. delete end   6. delete ele   7. exit");
    // scanf("%d",&ch);

    // switch (ch)
    // {
    // case 1: ins_beg();
    //         print();
    //         break;
    // case 2: ins_end();
    //         print();
    //         break;
    // case 3: printf("Enter element after which new element is to inserted:");
    //         scanf("%d",&ele);
    //         ins_ele(ele);
    //         print();
    //         break;
    // case 4: del_beg();
    //         print();
    //         break;

    // case 5: del_end();
    //         print();
    //         break;

    // case 6: printf("Enter element after which element is to be deleted");
    //         scanf("%d",&ele);
    //         del_ele(ele);
    //         print();
    //         break;

    // default:break;
    // }

    // } while (ch!=7);

    first=reverse(first);
    print();
    
    // struct node *tmp=first;
    // printf("Printing in reverse:");
    // printf("\nLinked list in reverse order\n");
    // printReverse(tmp);
    // mid_node(first);

    return 0;
}


