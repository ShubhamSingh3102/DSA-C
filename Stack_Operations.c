#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int size;
    int top;
    int *arr;
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
void push(struct Stack* ptr,int value)
{ 
    if(isFull(ptr))
    {
      printf("Stack Overflow! Cannot push %d to the stack\n",value);
    }
    else
    {
      ptr->top++;
      ptr->arr[ptr->top] = value;
    }
}
int pop(struct Stack* ptr)
{
    if(isEmpty(ptr))
    {
       printf("Stack Underflow! Cannot pop from the stack\n");
       return -1;
    }
    else
    {
       int value = ptr->arr[ptr->top];
       ptr->top--;
       return value;
    }
}
int main()
{
    struct Stack *sp=(struct Stack *)malloc(sizeof(struct Stack));//reserve memory in the heap using malloc
    sp->size = 10;
    sp->top = -1;//no element is present in the stack.....
    sp->arr = (int*)malloc(sp->size*sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Empty:%d\n",isEmpty(sp));
    printf("Full:%d\n",isFull(sp));
    push(sp,101);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,77);
    push(sp,69);
    push(sp,56);
    push(sp,88);//-->Pushed 10 values
    //push(sp,69);//Stack overflow since the size of the stack is 10
    printf("After pushing Empty:%d\n",isEmpty(sp));
    printf("After pushing Full:%d\n",isFull(sp));

    printf("Popped %d from the stack\n",pop(sp));//Last in first out concept(LIFO)
    printf("Popped %d from the stack\n",pop(sp));
    printf("Popped %d from the stack\n",pop(sp));
    printf("Popped %d from the stack\n",pop(sp));

    printf("After poping Empty:%d\n",isEmpty(sp));
    printf("After poping Full:%d\n",isFull(sp));
    return 0;
}