#include <stdio.h>
#include <stdlib.h>

void bfs(int adj[][10],int size,int nxt,int i,int status[],int queue[],int front,int rear)
{
    int j;
    if(i==size)
        return;
    else if(rear==-1)
    {
        rear=0;front=0;
        queue[rear]=nxt;
        status[rear]=2;
    }
    for(j=0;j<size;j++)
    {
        if(adj[nxt][j]==1 && status[j]!=3)
        {
            rear++;
            queue[rear]=j;
            status[j]=2;
        }
    }
    printf("%d ",queue[front]);
    if(status[front]==2)
        status[front]=3;
    front++;
    i++;
    bfs(adj,size,queue[front],i,status,queue,front,rear);
}


int main()
{
    int status[10],queue[10],size,i1,j1,adj[10][10];
    printf("enter size\n");
    scanf("%d",&size);
    for(i1=0;i1<size;i1++)
        status[i1]=1;

    printf("enter ADJECENCY matrix . . .\nenter 1 if neighbour & 0 if not.\n");

    for(i1=0;i1<size;i1++)
    {
        for(j1=0;j1<size;j1++)
        {
            scanf("%d",&adj[i1][j1]);
        }
    }

    printf(". . .using Recursive BSF to traverse. . .\n");
    bfs(adj,size,0,0,status,queue,0,-1);
    return 0;
}


