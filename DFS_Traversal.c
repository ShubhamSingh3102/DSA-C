#include<stdio.h>
#include<stdlib.h>
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

void DFS(int i)//i means jis node pe ham aabhi present h
{
    int j;
    //Jo node ham visit krenge usko print kr rhe h 
    printf("%d ",i);
    visited[i]=1;//node already visited marked
    for(int j=0;j<7;j++)
    {
        if(a[i][j]==1 && !visited[j])
        {
            DFS(j);
        }
    }
}
int main()
{
    //DFS Implementation 
    DFS(1);
    return 0;
}
