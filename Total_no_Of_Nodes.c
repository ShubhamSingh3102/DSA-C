#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node* CreateNode(int data)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int count=0;
int TotalNoOfNodes(struct node* root)
{
    if(root!=NULL)
    {
        count++;
        TotalNoOfNodes(root->left);
        TotalNoOfNodes(root->right);

    }
    return count;
}
int main()
{
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

    printf("Number of nodes in Binary tree is = %d ",TotalNoOfNodes(p));
    printf("\n");
    return 0;
}
