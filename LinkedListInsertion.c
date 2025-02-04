#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void LinkedListTraversal(struct Node* ptr)//struct naam ka ek pointer chahiye jo head ko point kr raha ho...
{
    while(ptr!=NULL)
    {
        printf("Element:%d\n",ptr->data);
        ptr = ptr->next;
    }
}
//Insertion At Beginning
struct Node* InsertAtFirst(struct Node* head,int data)//naya head return hoga jo ek naya linked list hoga
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));//ek node ko heap me allocate kiya...heap me memory dedi
    ptr->next=head;
    ptr->data=data;
    head=ptr;//ptr naya head ban gaya
    return head;
}
//Insertion In Between
struct Node* InsertAtIndex(struct Node* head,int data,int index)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));//ek node ko heap me allocate kiya...heap me memory dedi
    struct Node* p=head;
    int i=0;
    while(i!=index-1)//jaha insert krna hai uske ek kadam phele
    {
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
//Insertion At End
struct Node* InsertionAtEnd(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));//ek node ko heap me allocate kiya...heap me memory dedi
    struct Node* p=head;
    ptr->data=data;
    while(p->next!=NULL)//Standing at the end....
    {
        p = p->next;//NULL tk p traverse krega
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
//Insertion After Node
struct Node* InsertionAfterNode(struct Node* head,struct Node* prevNode,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));//ek node ko heap me allocate kiya...heap me memory dedi
    ptr->data=data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
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

    printf("Linked list before Insertion:\n");
    LinkedListTraversal(head);
    // head=InsertAtFirst(head,56); 
    // head=InsertAtIndex(head,56,2); 
    // head=InsertionAtEnd(head,56);
    head=InsertionAfterNode(head,second,88);
    printf("Linked list after Insertion:\n");
    LinkedListTraversal(head);
    return 0;
}