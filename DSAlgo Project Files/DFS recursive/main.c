#include<stdio.h>

int adj[20][20],top=0,stack[20]={0},status[20]={0};

void dfs_recursive(int a[][20],int start,int size)
{
    int i;
    if(top==-1)
        return;
    if(status[start]==0)
    {
        stack[top]=start;
        status[start]=1;
        printf("%c ",stack[top]+65);
    }
    for(i=0;i<size;i++)
    {
        if(a[start][i]==1 && status[i]==0)
        {
            stack[++top]=i;
            printf("%c ",stack[top]+65);
            status[i]=1;
            break;
         }
    }
    if(i==size)
        start=stack[--top];
    else
        start=stack[top];
    status[stack[top]]=2;
    dfs_recursive(a,start,size);
}

int main()
{
    void dfs_recursive(int[][20],int,int);
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
    dfs_recursive(adj,start_node,n);
    return 0;
}

