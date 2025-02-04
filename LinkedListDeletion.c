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

//Deleting first node from a linked list
struct Node* DeleteFirstNode(struct Node* head)
{
    struct node* ptr=head;
    head = head->next;
    free(ptr);
    return head;
}

//Deletion of node at index from a linked list
struct Node* DeleteAtIndex(struct Node* head,int index)
{
    struct Node *p=head;
    struct Node *q=head->next;//jo index delete krna chahte h...hamlog chahte h hamara q waha pe aa jae....
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

//Deletion of last node from a linked list
struct Node* DeleteLastNode(struct Node* head)
{
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

//Deletion of node with a given key/value
struct Node* DeleteAtValue(struct Node* head,int value)
{
    struct Node *p=head;
    struct Node *q=head->next;//jo index delete krna chahte h...hamlog chahte h hamara q waha pe aa jae....
   while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }

    if(q->data == value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}
int main()
{

    //Allocate memory for nodes in the linked list in Heap
    struct Node* head = (struct Node *)malloc(sizeof(struct Node));
    struct Node* second = (struct Node *)malloc(sizeof(struct Node));
    struct Node* third = (struct Node *)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node *)malloc(sizeof(struct Node));
    

    //Linked first and second nodes
    head->data = 7;
    head->next = second;

    //Linked second and third nodes
    second->data = 11;
    second->next = third;

    //Linked third node with fourth node
    third->data =66;
    third->next = fourth;

    //Terminate the list at the fourth node
    fourth->data =88;
    fourth->next = NULL;

    printf("Linked list before Deletion\n");
    LinkedListTraversal(head);

    // head=DeleteFirstNode(head);
    // head=DeleteAtIndex(head,2);
    // head=DeleteLastNode(head);
    head=DeleteAtValue(head,11);
    printf("Linked list after Deletion\n");
    LinkedListTraversal(head);
    return 0;
}