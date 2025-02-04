#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;//storage
    int f;//stores Indexes value
    int r;//stores Indexes value
    int *arr;
};
int isEmpty(struct Queue *q)
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
int isFull(struct Queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;//true
    }
    else
    {
        return 0;//false
    }
}
void Enqueue(struct Queue *q,int val)
{
    if(isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
    }
}
int Dequeue(struct Queue *q)
{
    int a=-1;//dequeue nhi kr paoge
    if(isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int main()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = 100;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size*sizeof(int));

    //Enqueue fews elements
    Enqueue(q,12);
    Enqueue(q,18);
    Enqueue(q,35);

    printf("Dequeuing element %d\n",Dequeue(q));
    printf("Dequeuing element %d\n",Dequeue(q));
    printf("Dequeuing element %d\n",Dequeue(q));

    if(isEmpty(q))
    {
        printf("The Queue is empty\n");
    }
    return 0;
}