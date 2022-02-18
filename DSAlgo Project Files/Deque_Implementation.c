#include<stdio.h>
#include<stdlib.h>
#define max_val 7

int deque[max_val];
int right=-1,left=-1;

int main()
{
int val;
void insert_from_right();
void insert_from_left();
void delete_from_right();
void delete_from_left();
void display();
printf("You have entered a DEQUE program.\n");
do{
printf("\n Enter your choice OR press 0 to close ");
printf("\n PRESS : \n\t 1) to insert from rear \n\t 2) to insert from front \n\t 3) to delete from rear \n\t 4) to delete from front \n\t 5) display \n");
scanf("%d",&val);
switch(val)
{
    case 1:
        insert_from_right();
        break;
    case 2:
        insert_from_left();
        break;
    case 3:
        delete_from_right();
        break;
    case 4:
        delete_from_left();
        break;
    case 5:
        display();
        break;
}
}while(val!=0);
return 0;
}

void insert_from_right()
{   int num_r;
    printf("Enter the number to be inserted from rear : ");
    scanf("%d",&num_r);
    if(left==0 && right==max_val-1)
    {
        printf("OVERFLOW\n");
        return;
    }
    if(right==-1 && left==-1)
    {
        right=0;
        left=0;
    }
    else
        {
        if(right==max_val-1)
        {
            right=0;
        }
        else
            {
            right=right+1;
            }
        }
     deque[right]=num_r;
     return;
}

void insert_from_left()
{   int num_l;
    printf("Enter the number to be inserted from front : ");
    scanf("%d",&num_l);
    if(left==0 && right==max_val-1)
    {
        printf("OVERFLOW\n");
        return;
    }
    if(right==-1 && left==-1)
    {
        right=0;
        left=0;
    }
    else
        {
        if(left==0)
        {
            left=max_val-1;
        }
        else
            {
            left=left-1;
            }
        }
     deque[left]=num_l;
     return;
}

void delete_from_right()
{
    if(left==-1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    if(right==0 && left==0)
    {
        left=-1;
        right=-1;
    }
    else
        {
        if(right==0)
        {
            right=max_val-1;
        }
        else
            {
            right=right-1;
            }
        }
     return;
}

void delete_from_left()
{
    if(left==-1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    if(right==0 && left==0)
    {
        left=-1;
        right=-1;
    }
    else
        {
        if(left==max_val-1)
        {
            left=0;
        }
        else
            {
            left=left+1;
            }
        }
     return;
}

void display()
{
    printf("\n Displaying modified deque :\n");
int start=left,end=right;
if(start==-1)
{
    printf("Nothing to display\n");
}
if(start<=end)
{
    while(start<=end)
    {
        printf("%d ",deque[start]);
        start=start+1;
    }
    printf("\n");
}
else
    {
    while(start<=max_val-1)
    {
        printf("%d ",deque[start]);
        start=start+1;
    }
    start=0;
    while(start<=end)
    {
        printf("%d ",deque[start]);
        start=start+1;
    }
    }
}
