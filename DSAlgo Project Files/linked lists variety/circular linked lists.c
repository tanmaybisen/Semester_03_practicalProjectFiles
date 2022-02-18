#include<stdio.h>
#include<stdlib.h>
#define max 5

struct node
{
int data;
struct node *next;
}*temp;

struct node *ptr;
struct node *first=NULL;

void create()
{
    int i=0,val,total;
    printf("enter total\n");
    scanf("%d",&total);
    for(i=0;i<total;i++)
    {
        printf("enter val \n");
        scanf("%d",&val);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=val;
        ptr=first;
        if(ptr==NULL)
        {
            first=temp;
            first->next=first;
        }
        else
        {
            ptr=first;
            while(ptr->next!=first)
            {
                ptr=ptr->next;

            }
            ptr->next=temp;
            ptr=temp;
            ptr->next=first;
        }
    }
}


void display()
{
    ptr=first;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=first);
    printf("\n");
    return;
}

int main()
{   printf("calling create\n");
    create();
    printf("calling display\n");
    display();
    return 0;
}
