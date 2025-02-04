#include<stdio.h>
#include<stdlib.h>
struct CircularQueue
{
    int size;//storage
    int f;//stores Indexes value
    int r;//stores Indexes value
    int *arr;
};
int isEmpty(struct CircularQueue *q)
{
    if(q->f==q->r)
    {
        return 1;//true
    }
    else
    {
        return 0;//false
    }
}
int isFull(struct CircularQueue *q)
{
    if((q->r+1)%q->size==q->f)//circular increment of rare is equal to front...
    {
        return 1;//true
    }
    else
    {
        return 0;//false
    }
}
void Enqueue(struct CircularQueue *q,int val)
{
    if(isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->r=(q->r+1) % q->size;
        q->arr[q->r]=val;
        printf("Enqued element: %d\n",val);
    }
}
int Dequeue(struct CircularQueue *q)
{
    int a=-1;//dequeue nhi kr paoge
    if(isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        q->f=(q->f+1) % q->size;
        a=q->arr[q->f];
    }
    return a;
}
int main()
{
    struct CircularQueue *q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->size = 4;
    q->f = 0;//queue kabhi full hi nhi hoga
    q->r = 0;//queue kabhi full hi nhi hoga
    q->arr = (int *)malloc(q->size*sizeof(int));

    //Enqueue fews elements
    Enqueue(q,12);
    Enqueue(q,18);
    Enqueue(q,35);

    printf("Dequeuing element %d\n",Dequeue(q));
    printf("Dequeuing element %d\n",Dequeue(q));
    printf("Dequeuing element %d\n",Dequeue(q));

    Enqueue(q,45);
    Enqueue(q,45);
    Enqueue(q,45);


    if(isEmpty(q))
    {
        printf("The Queue is empty\n");
    }

    if(isFull(q))
    {
        printf("The Queue is full\n");
    }

    return 0;
}