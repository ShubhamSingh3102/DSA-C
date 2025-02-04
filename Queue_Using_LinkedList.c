#include<stdio.h>
#include<stdlib.h>

struct Node *f=NULL;//global variable
struct Node *r=NULL;//global varaible

struct Node
{
    int data;
    struct Node* next;
};
void LinkedListTraversal(struct Node* ptr)//struct naam ka ek pointer chahiye jo head ko point kr raha ho...
{
    printf("Printing the elements of this linked list\n");
    while(ptr!=NULL)
    {
        printf("Element:%d\n",ptr->data);
        ptr = ptr->next;
    }
}
void Enqueue(int val)
{
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL)//Full condition
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data=val;
        n->next=NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else
        {
            r->next=n;
            r=n;
        }
    }
}
int Dequeue()
{
    int val=-1;
    struct Node *ptr=f;//ptr pointer pointing to the head...
    if(f=NULL)//Empty conditon
    {
        printf("Queue is empty\n");
    }
    else
    {
        f=f->next;
        ptr->data=val;
        free(ptr);
    }
    return val;
}
int main()
{
    LinkedListTraversal(f);
    printf("Dequeuing element %d\n",Dequeue());
    Enqueue(23);
    Enqueue(7);
    Enqueue(18);
    printf("Dequeuing element %d\n",Dequeue());
    LinkedListTraversal(f);
    return 0;
}