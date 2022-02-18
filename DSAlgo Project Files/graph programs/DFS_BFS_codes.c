#include <stdio.h>
#define MAX 4

void breadth_first_search(int adj[][MAX],int visited[],int start)
{
    int queue[MAX],rear=-1,front=-1,i;
    queue[++rear] = start;
    visited[start] = 1;
    while(rear != front)
    {
        start = queue[++front];
        if(start == 4)
            printf("5\t");
        else
            printf("%c ",start + 65);

        for(i = 0; i < MAX; i++)
        {
            if(adj[start][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void depth_first_search(int adj[][MAX],int visited[],int start)
{

int stack[MAX],top=-1,i;
printf("%c ",start + 65);
visited[start] = 1;
stack[++top] = start;
while(top!=-1)
{
    start = stack[top];
    for(i = 0; i < MAX; i++)
    {
        if(adj[start][i] && visited[i] == 0)
        {
            stack[++top] = i;
            printf("%c ", i + 65);
            visited[i] = 1;
            break;
        }
    }
    if(i == MAX)
        top--;
}
}

int main()
{
    int visited1[MAX] = {0},visited2[MAX] = {0};
    int adj[MAX][MAX],i,j;

    printf("\n Enter the adjacency matrix:\n");
    for(i = 0; i < MAX; i++)
    {printf("enter row %d\n",i+1);
        for(j = 0; j < MAX; j++)
            scanf("%d", &adj[i][j]);
    }

    printf("\n. . .BFS TRAVERSAL OF GRAPH. . .\n");
    breadth_first_search(adj,visited1,0);
    printf("\n. . .DFS TRAVERSAL OF GRAPH. . .\n");
    depth_first_search(adj,visited2,0);
    return 0;
}


