#include <stdio.h>
#include <stdlib.h>

int main()
{
    void BFS_non_recursive(int[][10],int,int,int[]);
    int j,i,a[10][10],n,visited[10];
    char first;
    printf("enter total no. of nodes : ");
    scanf("%d",&n);
    printf("enter matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("Enter node from where u wish to start traversal : ");
    getchar();
    scanf("%c",&first);
    first=(int)first;
    first=first-65;
    BFS_non_recursive(a,n,first,visited);
    printf("\n");
    return 0;
}

void BFS_non_recursive(int b[][10],int size,int start,int visit[])
{
    int rear=-1,front=-1,queue[size],i;
    rear=rear+1;
    queue[rear]=start;
    visit[start]=1;
    while(rear!=front)
    {
        front=front+1;
        start=queue[front];
        printf("%c ",start+65);
        for(i=0;i<size;i++)
        {
            if(b[start][i]==1 && visit[i]==0)
            {
                rear=rear+1;
                queue[rear]=i;
                visit[i]=1;
            }
        }
    }
}
