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
int left_height;
int right_height;
int max()
{
    if(left_height>right_height)
    {
        return left_height+1;
    }
    else
    {
        return right_height+1;
    }
}
int height(struct node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    else{
    left_height= height(root->left);
    right_height= height(root->right);
    }
    return max(left_height, right_height) + 1;
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

    printf("Height of the tree is = %d ",height(p));
    printf("\n");
    return 0;
}