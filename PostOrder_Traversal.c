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
void PostOrder(struct node* root)
{
    if(root!=NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    //Constructing the root node-Using function(Recommended)
    struct node *p=CreateNode(4);
    struct node *p1=CreateNode(1);
    struct node *p2=CreateNode(6);
    struct node *p3=CreateNode(5);
    struct node *p4=CreateNode(2);
    
    //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    PostOrder(p);
    return 0;
}