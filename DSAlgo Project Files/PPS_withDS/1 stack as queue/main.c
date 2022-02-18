//Consider you have a stack data structure and the application you have to create uses queue data structure.
//Can you implement queue data structure using stack.
//Write proper enqueue and dequeue methods and demonstrate the working in main().


#include <stdio.h>
#include <stdlib.h>

struct stack
{
int *A;
int top;
}*p,*q;

int size;

void create()
{   printf("Enter max size of queue : ");
    scanf("%d",&size);
    p=(struct stack*)malloc(sizeof(struct stack));
    p->A=(int*)malloc(size*sizeof(int));
    p->top=-1;
    q=(struct stack*)malloc(sizeof(struct stack));
    q->A=(int*)malloc(size*sizeof(int));
    q->top=-1;
    return;
}

void push(int value)
{
    if(p->top==size-1)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        p->top=p->top+1;
        p->A[p->top]=value;
        return;
    }
}

int pop(struct stack *n)
{
    int val;
    if(n->top==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        val=n->A[n->top];
        n->top--;
        return val;
    }
}


void enqueue(int val)
{
    push(val);
    return;
}

int dequeue()
{
    int del;
    q->top=-1;
    while(p->top!=-1)
    {
        q->top++;
        q->A[q->top]=p->A[p->top];
        p->top--;
    }
    del=pop(q);
    while(q->top!=-1)
    {
        p->top++;
        p->A[p->top]=q->A[q->top];
        q->top--;
    }
    return del;
}

void display(struct stack *n)
{
    int k;
    if(n->top==-1)
    {
        printf("Nothing to print \n");return;
    }
    for(k=0;k<=n->top;k++)
    {
        printf("%d ",n->A[k]);
    }
    printf("\n");
    return;
}

int main()
{   int kk,rec,val;
    create();
    do{
    printf("enter 0 to exit || choose : ");
    printf("1) enqueue 2) dequeue 3) display\n");
    scanf("%d",&kk);
    switch(kk)
    {
    case 1:
        printf("Enter value to be inserted\n");
        scanf("%d",&val);
        enqueue(val);break;
    case 2:
        rec=dequeue();
        if(rec!=-1)
        {
            printf("Deleted value is %d \n",rec);
        }
        break;
    case 3:
        display(p);break;
    }
    }while(kk!=0);
    return 0;
}




