#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;//struct node type ka pointer hai....
};

void LinkedListTraversal(struct Node* ptr)//struct naam ka ek pointer chahiye jo head ko point kr raha ho...
{
    while(ptr!=NULL)
    {
        printf("Element:%d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{

    //Allocate memory for nodes in the linked list in Heap
    struct Node* head = (struct Node *)malloc(sizeof(struct Node));
    struct Node* second = (struct Node *)malloc(sizeof(struct Node));
    struct Node* third = (struct Node *)malloc(sizeof(struct Node));

    //Linked first and second nodes
    head->data = 7;
    head->next = second;

    //Linked second and third nodes
    second->data = 11;
    second->next = third;

    //Terminate the list at the third node
    third->data =66;
    third->next = NULL;
    LinkedListTraversal(head);
    return 0;
}