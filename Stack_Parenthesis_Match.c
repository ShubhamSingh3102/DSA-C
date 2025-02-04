#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int size;
    int top;
    char* arr;
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
    if(ptr->top == ptr->size-1)
    {
        return 1;//true
    }
    else
    {
        return 0;//false
    }
}
void push(struct Stack* ptr,char value)
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
char pop(struct Stack* ptr)
{
    if(isEmpty(ptr))
    {
       printf("Stack Underflow! Cannot pop from the stack\n");
       return -1;
    }
    else
    {
       char value = ptr->arr[ptr->top];
       ptr->top--;
       return value;
    }
}
int parenthesisMatch(char* exp)
{
    struct Stack* sp;//pointer ko liya
    //Create and initialise the stack
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i] == '(')
        {
            push(sp,'(');
        }
        else if(exp[i] == ')')
        {
            if(isEmpty(sp))
            {
                return 0;
            }
            else
            {
                pop(sp);
            }
        }
    }
        if(isEmpty(sp))
        {
            return 1;//balanced expression
        }
        else
        {
            return 0;//unbalanced expression
        }
    }
int main()
{
    char *exp = "8*(9))";//valid parenthesis but not always valid expression....it always check valid parenthesis....

    if(parenthesisMatch(exp))
    {
        printf("The parenthesis is matching\n");
    }
    else
    {
        printf("The parenthesis is not matching\n");
    }
    return 0;
}
