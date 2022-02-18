#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
}*temp;

struct node *front=NULL,*rear=NULL;

void insert()
{
    int val;
    printf("enter data\n");
    scanf("%d",&val);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if(front==NULL)
        {
        front=temp;
        rear=temp;
        rear->next=NULL;
        front->next=NULL;
        }
    else
    {
        while(rear->next!=NULL)
        {
            rear=rear->next;
        }

        rear->next=temp;
    }
}


void display()
{   struct node *ptr;
    ptr=front;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void del()
{   struct node *pre_ptr;
    ptr=front;
    while(ptr->next!=NULL)
    {   pre_ptr=ptr;
        ptr=ptr->next;
    }
    pre_ptr->next=NULL;
    free(ptr);
    return;
    }
}

int main()
{   int val;
    printf("you have entered a menu driven program\n");
    do{
    printf("enter ur choice 1-3 || 0 to exit loop \n");
    printf("\n\t 1) insert \n\t 2) delete \n\t 3) display \n");
    scanf("%d",&val);
    switch(val)
    {
 case 1:
    insert();
    display();
    break;
 case 2:
    del();
    display();
    break;
 case 3:
    display();
    break;
    }

    }while(val!=0);
     return 0;
}










