#include<stdio.h>
#include<stdlib.h>
#define max 5

struct node
{
int data;
struct node *next;
struct node *prev;
}*temp;

struct node *ptr;
struct node *first=NULL;

void create()
{
    int val;
    printf("enter val \n");
    scanf("%d",&val);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    ptr=first;
    if(ptr==NULL)
    {
        first=temp;
        first->next=NULL;
        first->prev=NULL;
    }
    else{
        ptr=first;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;

        }
        ptr->next=temp;
        temp->prev=ptr;
        ptr=temp;
        ptr->next=NULL;
    }
}


void display()
{   ptr=first;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}

int main()
{   printf("calling create\n");
    create();create();create();create();create();
    printf("calling display\n");
    display();
}
