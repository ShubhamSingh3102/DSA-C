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
int IsEmpty(struct Node* top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsFull(struct Node* top)
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));//heap me memory allocate kiye
    if(n == NULL)//dynamically memory allocate nahi ho payi....
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node* Push(struct Node* top , int x)
{
    if(IsFull(top))//Stack is Full
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct Node** top)
{
    if(IsEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node* n=*top;//temporary pointer for pointing to the head position....
        *top= (*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}

int peek(struct Node* top,int pos)
{
    struct Node* ptr=top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int StackTop(struct Node* top)
{
    return top->next;
}
int StackBottom(struct Node* top)
{
    struct Node* ptr=top;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    return ptr->data;
}
int main()
{
    struct Node* top = NULL; //initially linked list is empty...
    top = push(top,88);
    top = push(top,2);
    top = push(top,18);
    top = push(top,45);
   
    LinkedListTraversal(top);
    for(int i=1;i<=4;i++)
    {
        printf("Value at position %d is : %d\n",i,peek(top,1));
    }
    printf("The topmost value of this stack is :%d\n",StackTop(top));
    printf("The bottommost value of this stack is :%d\n",StackBottom(top));
    return 0;
}






// #include<stdio.h>
// #include<stdlib.h>
// struct Node
// {
//     int data;
//     struct Node* next;
// };
// struct Node* top = NULL;//globabl variable
// void LinkedListTraversal(struct Node* ptr)//struct naam ka ek pointer chahiye jo head ko point kr raha ho...
// {
//     while(ptr!=NULL)
//     {
//         printf("Element:%d\n",ptr->data);
//         ptr = ptr->next;
//     }
// }
// int IsEmpty(struct Node* top)
// {
//     if(top == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int IsFull(struct Node* top)
// {
//     struct Node* n = (struct Node*)malloc(sizeof(struct Node));//heap me memory allocate kiye
//     if(n == NULL)//dynamically memory allocate nahi ho payi....
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// struct Node* Push(struct Node* top , int x)
// {
//     struct Node* n = (struct Node*)malloc(sizeof(struct Node));
//     if(n == NULL)//Stack is Full
//     {
//         printf("Stack Overflow\n");
//     }
//     else
//     {
//         n->data=x;
//         n->next=top;
//         top=n;
//         return top;
//     }
// }
// int pop(struct Node* top)
// {
//     if(IsEmpty(top))
//     {
//         printf("Stack Underflow\n");
//     }
//     else
//     {
//         struct Node* n=top;//temporary pointer for pointing to the head position....
//         top= top->next;
//         int x=n->data;
//         free(n);
//         return x;
//     }
// }
// int main()
// {
//     struct Node* top = NULL; //initially linked list is empty...
//     top = push(top,88);
//     top = push(top,2);
//     top = push(top,18);
    
//     LinkedListTraversal(top);

//     int element = pop(top);
//     printf("Popped element is %d\n",element);
//     LinkedListTraversal(top);
//     return 0;
// }