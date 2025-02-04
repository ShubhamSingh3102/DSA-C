#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct Stack* ptr)
{
    if(ptr->top == -1)//condition of stack to be empty
    {
        return 1;//true
    }
    else
    {
        return 0;//false
    }
}

int isFull(struct Stack* ptr)
{
    if(ptr->top == ptr->size-1)//condition of stack to be full
    {
        return 1;//true
    }
    else
    {
        return 0;//false
    }
}
int main()
{
    // struct Stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int*)malloc(s.size*sizeof(int));

    struct Stack *s=(struct Stack *)malloc(sizeof(struct Stack));//structure ka ek pointer ban gya
    s->size = 80;//fixed size ka array
    s->top = -1;//aabhi tk koi element nhi daala hai...
    s->arr = (int*)malloc(s->size*sizeof(int));//reserve memory in the heap using malloc

    //Pushing an element manually in the stack 
    s->arr[0]=7;
    s->top++;
    // s->arr[1]=3;
    // s->top++;
    //Check if stack is empty
    if(isEmpty(s))
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty\n");
    }
    if(isFull(s))
    {
        printf("The stack is full");
    }
    else
    {
        printf("The stack is not full");
    }
    return 0;
}