#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
char StackTop(struct Stack *sp)
{
    return sp->arr[sp->top];
}
int Precedence(char ch)
{
    if(ch=='*' || ch=='/')
    {
        return 3;
    }
    else if(ch=='+' || ch=='-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *infixToPostfix(char *infix)
{
    struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    char *postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));

    int i=0;//Infix scanner
    int j=0;//Postfix filling
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else
        {
            if(Precedence(infix[i])>Precedence(StackTop(sp)))
            {
                push(sp,infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char *infix = "x+y*z-k";
    printf("Postfix Expression is: %s",infixToPostfix(infix));
    return 0;
}
