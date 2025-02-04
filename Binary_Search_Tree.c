#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* CreateNode(int data)
{
    struct node* n;//Creating a node pointer
    n = (struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void InOrder(struct node* root)
{
    if(root!=NULL)
    {
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}

int isBST(struct node* root)
{
    static struct node* prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data <=prev->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
int main()
{
    //Constructing the root node-Using function(Recommended)
    struct node *p=CreateNode(5);
    struct node *p1=CreateNode(3);
    struct node *p2=CreateNode(6);
    struct node *p3=CreateNode(1);
    struct node *p4=CreateNode(4);
    
    //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    InOrder(p);
    printf("\n");
    printf("%d",isBST(p));
    return 0;
}