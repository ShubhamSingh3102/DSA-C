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
    q->size = 400;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(q->size*sizeof(int));

    //BFS Implementation
    int node;
    int i=0;//Starting from 0th index
    int visited[7]={0,0,0,0,0,0,0};//Initialised an empty array
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d",i);
    visited[i]=1;//Marked source node s as visited
    Enqueue(&q,i);//Enqueue i for exploration
    while(!isEmpty(&q))
    {
        int node = Dequeue(&q);
        for(int j=0;j<7;j++)
        {
            if(a[node][j]==1 && visited[j]==0)
            {
                printf("%d",j);
                visited[j]=1;//mark as visited
                Enqueue(&q,j);//Enqueue for exploration
            }
        }
    }
    return 0;
}
