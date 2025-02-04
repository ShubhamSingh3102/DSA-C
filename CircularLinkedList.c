#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void LinkedListTraversal(struct Node* head)
{
    struct Node* ptr= head;//ek pointer banao jo ki head ko point kare...
    // printf("Element is %d\n",ptr->data);//initial push given to ptr
    // ptr= ptr->next;
    // while(ptr!=head)
    // {
    //     printf("Element is %d\n",ptr->data);
    //     ptr= ptr->next;
    // }

    do{
        printf("Element is %d\n",ptr->data);
        ptr= ptr->next;
    }while(ptr!=head);
}

struct Node* InsertAtFirst(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));//ek node ko heap me allocate kiya...heap me memory dedi
    ptr->data=data;
    struct Node* p= head->next;
    while(p->next!=head)
    {
        p = p->next;
    }
    //At this point p points to the last node of this circular linked list

    p->next= ptr;
    ptr->next= head;
    head=ptr;
    return head;
}

int main()
{
    struct Node* head = (struct Node *)malloc(sizeof(struct Node));
    struct Node* second = (struct Node *)malloc(sizeof(struct Node));
    struct Node* third = (struct Node *)malloc(sizeof(struct Node));
    struct Node* fourth= (struct Node*)malloc(sizeof(struct Node));


    //Linked first and second nodes
    head->data = 7;
    head->next = second;

    //Linked second and third nodes
    second->data = 11;
    second->next = third;

    //Linked third and fourth nodes
    third->data =66;
    third->next = fourth;

    //Circular Linked list me fourth ka next head ko point krega
    fourth->data=8;
    fourth->next=head;
    
    printf("Circular Linked list before Insertion\n");
    LinkedListTraversal(head);
    InsertAtFirst(head,123);
    printf("Circular Linked list after Insertion\n");
    LinkedListTraversal(head);
    return 0;
}