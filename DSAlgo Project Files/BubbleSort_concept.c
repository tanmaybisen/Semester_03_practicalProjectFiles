#include <stdio.h>
#include <stdlib.h>
#define max 5

//all sorting algorithms in one stack program
//bubble
//insertion
//selection
//shell
//quick
//merge
//heap

struct stack
{
    int *A;
    int top;
}*a1,*a2;

void create()
{
    a1=(struct stack *)malloc(sizeof(struct stack));
    a1->A=(int*)malloc(max*sizeof(int));
    a1->top=-1;
    a2=(struct stack *)malloc(sizeof(struct stack));
    a2->A=(int*)malloc(max*sizeof(int));
    a2->top=-1;

}

void push(struct stack *b1,int val)
{
    if(b1->top==(max-1))
    {
        printf("Strack full\n");
    }
    else
    {
        b1->top++;
        b1->A[b1->top]=val;
    }
    return;
}

int pop(struct stack *b1)
{
    int store;
    if(b1->top==-1)
    {
        printf("stack empty\n");
        return -1;
    }
    else
    {
        store=b1->A[b1->top];
        b1->top--;
        return store;
    }
}

void bubble(struct stack *b1)
{
    int i,j,temp;
    for(i=0;i<max;i++)
    {
        for (j=i+1;j<max;j++)
        {
            if(b1->A[i]>b1->A[j])
            {
                temp=b1->A[i];
                b1->A[i]=b1->A[j];
                b1->A[j]=temp;
            }
        }
    }
}

void insertion(struct stack *b1)
{
    int temp,pos,i;
    for (i=1;i<max;i++)
    {
        pos=i;
        temp=b1->A[i];
        while(pos > 0 && (temp < b1->A[pos-1]))
        {
            b1->A[pos]=b1->A[pos-1];
            pos--;
        }
        a1->A[pos]=temp;
    }
}

void selection(struct stack *b1)
{
    int i,j,temp,sp;
    for(i=0;i<max;i++)
    {
        sp=i;
        for(j=i+1;j < max;j++)
        {
            if(b1->A[j] < b1->A[sp])
            {
                sp=j;
            }
        }
        temp=b1->A[sp];
        b1->A[sp]=b1->A[i];
        b1->A[i]=temp;
    }
}

void shell(struct stack *b1)
{
    int c,flag,i,temp;
    c=max;
    while(flag==1 || (c > 1))
    {
        flag=0;
        c=((c+1)/2);
        for (i=0; i<(max-c); i++)
        {
            if(b1->A[i] > b1->A[c+i])
            {
                temp=b1->A[i];
                b1->A[i]=b1->A[i+c];
                b1->A[i+c]=temp;
                flag=0;
            }
        }
    }
    return;
}

int partition(struct stack *b1,int beg,int end)
{
int loc,left,right,flag=0,temp;
left=beg;
right=end;
loc=left;
while(flag!=1)
{
while((b1->A[loc]<=b1->A[right]) && (loc!=right))
{
    right=right-1;
}
if(loc==right)
{
    flag=1;
}
else
    {
        if(b1->A[loc] > b1->A[right])
        {
          temp=b1->A[loc];
          b1->A[loc]=b1->A[right];
          b1->A[right]=temp;
          loc=right;
        }
    }
}
//hey this is the next part
if(flag==0)
{
while((b1->A[loc]>=b1->A[left]) && (loc!=left))
{
    left=left+1;
}
if(loc==left)
{
    flag=1;
}
else
    {
        if(b1->A[loc]<b1->A[left])
        {
          temp=b1->A[loc];
          b1->A[loc]=b1->A[left];
          b1->A[left]=temp;
          loc=left;
        }
    }

}
return loc;
}

void quick_sort(struct stack *b1,int beg,int end)
{int loc;
if(beg<end)
    {
    loc=partition(a1,beg,end);
    quick_sort(a1,beg,loc-1);
    quick_sort(a1,loc+1,end);
    }
}

void display(struct stack *b1)
{
    int i;
    for (i=0;i<max;i++)
    {
        printf("%d ",b1->A[i]);
    }
    printf("\n");
}

int main()
{
    int i=0,val;
    create();
    printf("enter data :\n");
    for(i=0;i<max;i++)
    {
        scanf("%d",&val);
        push(a1,val);
    }
    display(a1);
    //bubble(a1);
    //insertion(a1);
    //selection(a1);
    //shell(a1);
    //quick_sort(a1,0,max);
    //mergesort(a1,a2,0,max);
    display(a1);
    return 0;
}





