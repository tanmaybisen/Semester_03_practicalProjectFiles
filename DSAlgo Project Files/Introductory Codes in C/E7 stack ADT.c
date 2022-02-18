#include<stdio.h>
#include<stdlib.h>
#define max 5
struct stacking
{
int *stack;
int top;
}*p,*q,*r;

void create()
{
p=(struct stacking*)malloc(sizeof(struct stacking));
p->stack=(int*)malloc(max*sizeof(int));
p->top=-1;
q=(struct stacking*)malloc(sizeof(struct stacking));
q->stack=(int*)malloc(max*sizeof(int));
q->top=-1;
r=(struct stacking*)malloc(sizeof(struct stacking));
r->stack=(int*)malloc(max*sizeof(int));
r->top=-1;
return;
}

void push(struct stacking *c,int val)
{
if(c->top==(max-1))
printf("stack is full\n");
else
c->stack[++(c->top)]=val;
return;
}

int pop(struct stacking *c)
{
int val;
    if(c->top==-1)
    {
    printf("stack empty\n");
    return -1;
    }
    else
    {
    int val=c->stack[c->top];
    c->top--;
    return val;
    }
}

void display(struct stacking *ptr_var)
{
int k;
for(k=0;k < max;k++)
{
printf("%d ",ptr_var->stack[k]);
}
printf("\n");
}

void copy(struct stacking *a,struct stacking *b,struct stacking *c)
{
int k,t,nval;
for(k=max;k > -1;k--)
{
t=pop(a);
push(b,t);
}

for(k=max;k > -1;k--)
{
nval=pop(b);
push(c,nval);
}
}

int peep(struct stacking *a)
{
    if(a->top==-1)
    {
    printf("STACK EMPTY\n");
    return -1;
    }
    else
    return a->stack[a->top];
}

int main()
{
void create();
void copy(struct stacking *p,struct stacking *q,struct stacking *r);
void display(struct stacking *p);
void push(struct stacking *p,int);
int pop(struct stacking *p);
int peep(struct stacking *p);
int n,k,val,value,val_new,val_new1;

create();
printf("  YOU ENTERED IN PROGRAM THAT COPIES STACKS.\n\tCreate a STACK to be copied.\n\n");

for(k=0;k < max;k++)
{
printf("Enter element %d: ",k+1);
scanf("%d",&value);
push(p,value);
}

printf("THIS IS A MENU DRIVEN PROGRAM\npress the number to perform the corresponding operation\n\n");
printf("1)display\n2)copy\n3)peep\n");

do{
printf("ENTER YOUR CHOICE 1-3 || 0 TO EXIT\n");
scanf("%d",&val);
switch(val)
{
case 1:
printf("To display original stack enter '0'.\nTo display coppied stack enter '1'.\n");
scanf("%d",&val_new);
if(val_new==0)
{
printf("displaying original stack : ");
display(p);
}
if(val_new==1)
{
printf("displaying copied stack : ");
display(r);
}
break;

case 2:
copy(p,q,r);
break;

case 3:
printf("To peep original stack enter '0'.\nTo peep coppied stack enter '1'.\n");
scanf("%d",&val_new1);
if(val_new1==0)
{
n=peep(p);
printf("The element at TOP is : %d\n",n);
}
if(val_new1==1)
{
n=peep(r);
printf("The element at TOP is : %d\n",n);
}
}
}while(val!=0);
return 0;
}



