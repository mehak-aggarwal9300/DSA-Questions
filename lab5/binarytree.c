#include<stdlib.h>
#include<stdio.h>

typedef struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
}node;

node *root;

node* create_node()
{
    node *n;
    n = (node*) malloc(sizeof(node));
    printf("\ncreate_node");
    scanf("%d",&n->val);
    n->left=NULL;
    n->right=NULL;
    return n;
}

node* Construct(node* n,int sa[],int idx, int size)
{   if(idx==size)
    {
        return NULL;
    }   

    node* nn=(node*) malloc(sizeof(node));
    nn->val=sa[idx];
    nn->left=NULL;
    nn->right=NULL;
    if(root==NULL) 
    { 
        root=nn;
        return root;
    }

    if(!n->left)
    {
        n->left=nn;
        Construct(sa,idx+1,size);
    }
    root->right=Construct(sa,mid+1,hi);
    return root;
}

//java

static Node construct2(int[] pre,int psi,int pei,int[] in,int isi,int iei)
{   
    if(psi>pei||isi>iei)
    {return null;}
    Node root=new Node();
    root.data=pre[psi];
    int loc=-1;
    for(int i=isi;i<=iei;i++)
    {   
        if(pre[psi]==in[i])
        {
            loc=i;
            break;
        }

    }
    int lhs=loc-isi;
    root.left=construct2(pre,psi+1,psi+lhs,in,isi,loc-1);
    root.right=construct2(pre,psi+lhs+1,pei,in,loc+1,iei);
    return root;
}

node* insert(int arr[],int n)
{
    
    for(int i=0;i<n;i++)
    {
        if(root==NULL)
        {
            root = create_node();
            return root;
        }
        node *n=create_node();
        if(root->left==NULL) root->left=n;
        else if(root->right==NULL) root->right=n;
        else
        {   
            node *tmp=root;
            while(1)
            {
                tmp=tmp->left;
            }
        }



    }
}

preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}



