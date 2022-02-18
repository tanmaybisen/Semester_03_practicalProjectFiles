
//circular queue implemented

#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
void insert();
void delete();
void display();
int front = -1, rear = -1;
int queue[maxsize];
int main ()
{
    int choice;
    while(choice != 4)
    {
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice ?");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert();
            display();
            break;
            case 2:
            delete();
            display();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nEnter valid choice??\n");
        }
    }
}
void insert()
{
    int item;
    printf("\nEnter the element\n");
    scanf("%d",&item);
    if((rear+1)%maxsize == front)
    {
        printf("\nOVERFLOW");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == maxsize -1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear = (rear+1)%maxsize;
    }
    queue[rear] = item;
    printf("\nValue inserted ");
}
void delete()
{
    if(front == -1 && rear == -1)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(front == maxsize -1)
        {
            front = 0;
        }
    else
        front = front + 1;
}

void display()
{
   int i;
   if(front == -1)
   {
   printf("\nCircular Queue is Empty!!!\n");
   }
   else
   {
        i = front;
        if(front <= rear)
        {
            while(i <= rear)
            {printf("%d ",queue[i++]);}
        }
        else
        {
             while(i <= maxsize - 1)
            {printf("%d ", queue[i++]);}
        i = 0;
             while(i <= rear)
            {printf("%d ",queue[i++]);}
        }
   }
}



