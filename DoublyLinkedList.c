#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

void LinkedListTraversal(struct Node* head)
{
    struct Node* ptr= head;
    ptr->prev = NULL;
    while(ptr!=NULL)
    {
        printf("Element is %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    
    //Linked head with second node
    head->data=56;
    head->next=second;
    head->prev=NULL;

    //Linked second with third
    second->data=7;
    second->next=third;
    second->prev=head;

    //Linked third with fourth
    third->data=13;
    third->next=fourth;
    third->prev=second;

    //Terminate at fourth node
    fourth->data=45;
    fourth->next=NULL;
    fourth->prev=third;
    LinkedListTraversal(head);
}