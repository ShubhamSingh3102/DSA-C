#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
};
int GetHeight(struct node* n)
{
    if(n==NULL)
    {
        return 0;
    }
    return n->height;
}
struct node* CreateNode(int key)
{
    struct node* Node=(struct node*)malloc(sizeof(struct node));
    Node->key=key;
    Node->left=NULL;
    Node->right=NULL;
    Node->height=1;
    return Node;
}
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int GetBalanceFactor(struct node* n)
{
    if(n==NULL)
    {
        return 0;
    }
    return GetHeight(n->left) - GetHeight(n->right);
}
struct node* RightRotate(struct node* y)
{
    struct node* x=y->left;
    struct node* T2=x->right;

    x->right= y;
    y->left= T2;

    //Height updation
    y->height = max(GetHeight(y->right), GetHeight(y->left))+1;
    x->height = max(GetHeight(x->right), GetHeight(x->left))+1;

    return x;
}

struct node* LeftRotate(struct node* x)
{
    struct node* y=x->right;
    struct node* T2=y->left;

    y->left= x;
    x->right= T2;

    y->height = max(GetHeight(y->right), GetHeight(y->left))+1;
    x->height = max(GetHeight(x->right), GetHeight(x->left))+1;

    return y;
}
//Binary search tree Insertion
struct node* Insert(struct node* Node,int key)
{
    if(Node==NULL)
        return (CreateNode(key));
    if(key<Node->key)
        Node->left= Insert(Node->left,key);
    else if(key>Node->key)
        Node->right= Insert(Node->right,key);
        return Node;

    //Leaf node se height update krte hue aa rhe h
    Node->height= 1 + max(GetHeight(Node->left), GetHeight(Node->right));
    int bf=GetBalanceFactor(Node);

    //Left Left case

    if(bf>1 && key<Node->left->key){
       return RightRotate(Node);
    }
    //Right Right case

    if(bf<-1 && key>Node->right->key){
       return LeftRotate(Node);
    }
    //Left Right case

    if(bf>1 && key>Node->left->key){
        Node->left = LeftRotate(Node->left);
        return RightRotate(Node);
    }
    //Right Left case

    if(bf<-1 && key<Node->right->key){
        Node->right = RightRotate(Node->right);
        return LeftRotate(Node);
    }
    return Node;
}
void PreOrder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
int main()
{
    struct node* root = NULL;
    
    root=Insert(root,1);
    root=Insert(root,2);
    root=Insert(root,4);
    root=Insert(root,5);
    root=Insert(root,6);
    root=Insert(root,3);
    PreOrder(root);
    return 0;
}