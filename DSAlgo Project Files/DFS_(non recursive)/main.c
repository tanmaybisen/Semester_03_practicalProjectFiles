#include <stdio.h>
#include <stdlib.h>

int main()
{
    void DFS_non_recursive(int[][10],int[],int,int);
    int j,i,a[10][10],visited[10]={0},n;
    char start_node;
    printf("enter total no. of node : ");
    scanf("%d",&n);
    printf("enter matrix :\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("enter starting node : ");
    getchar();
    scanf("%c",&start_node);
    start_node=(int)start_node;
    start_node=start_node-65;
    DFS_non_recursive(a,visited,n,start_node);
    return 0;
}

void DFS_non_recursive(int b[][10],int visit[],int size,int start)
{
    int stack[10],i,top=-1;
    top=top+1;
    stack[top]=start;
    visit[start]=1;
    printf("%c ",start+65);
    while(top!=-1)
    {
        start=stack[top];
        for(i=0;i<size;i++)
        {
            if(b[start][i]==1 && visit[i]==0)
            {
                top=top+1;
                stack[top]=i;
                visit[i]=1;
                printf("%c ",i+65);
                break;
            }
        }
        if(i==4)
            top--;
    }
}
