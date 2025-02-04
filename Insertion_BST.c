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
//Code for searching in Binary Search Tree

struct node* SearchIter(struct node* root,int key)
{
    while(root!=NULL)
    {
        if(key==root->data)
        {
            return root;
        }
        else if(key<root->data)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return NULL;
}
void insert(struct node* root,int key)
{
    struct node* prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data)
        {
            printf("Value cannot be inserted %d, already in the BST",key);
            return;
        }
        else if(key<root->data)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    struct node* new= CreateNode(key);
    if(key<prev->data)
    {
        prev->left=new;
    }
    else
    {
        prev->right=new;
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

    insert(p,7);
    printf("%d",p->right->right->data);
    printf("\n");
    InOrder(p);
    return 0;
}