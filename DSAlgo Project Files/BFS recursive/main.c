#include<stdio.h>

int adj[20][20],front=0,rear=-1,queue[20]={0},status[20]={0};

void bfs_recursive(int a[][20],int start,int size)
{
    int i;
    if(front==size)
        return;
    if(status[start]==0)
    {
        rear=rear+1;
        queue[rear]=start;
    }
    for(i=0;i<size;i++)
    {
        if(a[start][i]==1 && status[i]==0)
        {
            rear=rear+1;
            queue[rear]=i;
            status[i]=1;
         }
    }
    printf("%c ",queue[front]+65);
    status[queue[front]]=2;
    front=front+1;
    start=queue[front];
    bfs_recursive(a,start,size);
}

int main()
{
    void bfs_recursive(int[][20],int,int);
    int i,j,n;
    char start_node;
    printf("enter total no. vertices : ");
    scanf("%d",&n);
    printf("enter matrix :\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    printf("enter the node to start form : ");
    getchar();
    scanf("%c",&start_node);
    start_node=(int)start_node;
    start_node=start_node-65;
    bfs_recursive(adj,start_node,n);
    return 0;
}
