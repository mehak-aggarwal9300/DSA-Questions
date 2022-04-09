#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct bst
{
    int val;
    struct bst *left;
    struct bst *right;
}bst;

bst *root;

void display(bst *root)
{
    if(root==NULL)return;


        if(root->left!=NULL) printf("%d ->", root->left->val);
        else printf(".->");

        printf("%d",root->val);

        if(root->right!=NULL) printf("<- %d", root->right->val);
        else printf("<-.");

        printf("\n");
        display(root->left);
        display(root->right);
}

bst* Construct(int sa[],int lo, int hi)
{   if(lo>hi)
    {
        return NULL;
    }   
    
    int mid=(lo+hi)/2;
    bst* root=(bst*) malloc(sizeof(bst));
    root->val=sa[mid];
    root->left=Construct(sa,lo,mid-1);
    root->right=Construct(sa,mid+1,hi);
    return root;
}

    int find(bst* node,int data)
{   if(node==NULL)return 0;
    if(node->val==data)
        return 1;
    if(data<node->val)
    {int l=find(node->left,data);
    if(l)return l;
    
    }else
    {
        int r=find(node->right,data);
        if(r)return r;
    }
    return 0;
}

     bst* add(bst* node,int data)
     {   if(node==NULL)
        {
            bst* n=(bst*) malloc(sizeof(bst));
            n->val=data;
            n->left=NULL;
            n->right=NULL;
            return n;
        }
        if(node->val==data)
        {
            return NULL;
        }
        if(node->val<data)
        {
            node->right=add(node->right,data);
            
        }
        else {
            node->left=add(node->left,data);
        }
        return node;
    }


    bst* remov(bst* node,int data)
    {
        if(node->val==data)
        {
            if(node->left==NULL&&node->right==NULL) return NULL;
            else if(node->left==NULL||node->right==NULL)    //one child
            {
                if(node->left==NULL)return node->right;
                else return node->left;
            }
            else{ //2 child
                int lmax=max(node->left);
                node->val=lmax;
                node->left= remov(node->left,lmax);
                return node; 
            }
        }
        else if(node->val<data)
        {
            node->right= remov(node->right,data);
        }
        else
        {
            node->left= remov(node->left,data);

        }
        return node;
    }

    int max(bst* node)
    {   if(node->right==NULL)return node->val;
        else 
        { int m;
            m = max(node->right);
            return m;
        }
        
    }


preorder(bst *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

inorder(bst *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

postorder(bst *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}


int main()
{
    int sa[]={12,25,37,50,62,75,87};
    int n= sizeof(sa)/sizeof(sa[0]);
    root=Construct(sa,0,n-1);
    display(root);
    printf("\n\nadd->40\nadd->90\n\n");
    add(root,40);
    add(root,90);
    display(root);
    printf("\nremove->62\nremove->37\nremove->25\n\n");
    remov(root,62);
    remov(root,37);
    remov(root,25);
    display(root);
    
    int data;
    printf("\nEnter no. to be searched");
    scanf("%d",&data);
    if(find(root,data)) printf("%d found\n",data);
    else printf("%d not found\n",data);
    
    printf("\npreorder:");
    preorder(root);
    printf("\npostorder:");
    postorder(root);
    printf("\ninorder:");
    inorder(root);

    return 0;
}