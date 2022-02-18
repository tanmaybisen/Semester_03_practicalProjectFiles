#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct graph_node
{
    char data;
    struct graph_node *next;
};

typedef struct graph_node node;

void graph_creator(node *adj[],int num)
{
    getchar();

    int j,n,cc=0;
    char i,tk[100];

    node *last,*a1;

    i='A';
    while(cc!=num)
    {
        last=NULL;
        printf("enter all neighbour nodes of %c :\n",i);
        gets(tk);
        n=strlen(tk);
        for(j=1;j<(n+1);j++)
        {

            a1=(node*)malloc(sizeof(node));
            a1->data=tk[j-1];
            a1->next=NULL;
            if(adj[cc]==NULL)
                adj[cc]=a1;
            else
                last->next=a1;
            last=a1;
        }
        cc++;
        i++;
    }
}

void out_deg_cal(node *adj[],int num,char ver)
{
    node *ptr1=NULL;
    char i='A';
    int count=0,n=0;
    while(i!=ver)
    {
        n++;i++;
    }
    ptr1=adj[n];
    while(ptr1!=NULL)
    {
        count++;
        ptr1=ptr1->next;
    }
    printf("The out degree of %c is %d.\n",ver,count);
}

void in_deg_cal(node *adj[],int num,char ver)
{
    node *ptr1=NULL;
    int i=0,count=0;
    for (i=0;i<num;i++)
    {
        ptr1=adj[i];
        while(ptr1!=NULL)
        {
            if(ptr1->data==ver)
            {
                count++;
            }
            ptr1=ptr1->next;
        }
    }
    printf("The in degree of %c is %d.\n",ver,count);
}


void display_graph(node *adj[],int num)
{
    node *ptr;
    char i='A';
    int k=0;
    while(k!=num)
    {
        ptr=adj[k];
        printf("neighbours of node %c are:\n",i);
        while(ptr!=NULL)
        {
            printf("%c ",ptr->data);
            ptr=ptr->next;
        }
        k++;
        i++;
        printf("\n");
    }
}

int main()
{
    node *adj[50];
    int i,num,value;
    char ver;
    printf("enter total nodes in graph\n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        adj[i]=NULL;
    }
    graph_creator(adj,num);
    printf("the graph is \n");
    display_graph(adj,num);
    do{
    printf("VERTEX for in deg & out deg calculation is : ");
    scanf("%c",&ver);
    in_deg_cal(adj,num,ver);
    out_deg_cal(adj,num,ver);
    printf("1 continue || 0 exit loop\n");
    scanf("%d",&value);
    getchar();
    }while(value!=0);
    return 0;
}
