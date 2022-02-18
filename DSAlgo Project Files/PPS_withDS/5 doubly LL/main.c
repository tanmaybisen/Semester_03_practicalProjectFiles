//Implement a c program for the following operations on doubly linked lists(DLL)
//a).create a DLL using end insertion
//b).reverse DLL using function

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*q;

struct node *create_end_insert(struct node *first)
{
    struct node *ptr;
    int i,total,value;
    printf("Enter how many nodes you want to insert from end : ");
    scanf("%d",&total);
    for(i=0;i<total;i++)
    {
        printf("enter data of node %d: ",i+1);
        scanf("%d",&value);
        ptr=first;
        q=(struct node*)malloc(sizeof(struct node));
        q->next=NULL;
        q->prev=NULL;
        q->data=value;
        if(ptr==NULL)
        {
            first=q;
            first->next=NULL;
            first->prev=NULL;
        }
        else
        {
            ptr=first;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=q;
            q->prev=ptr;
        }
    }
    return first;
}

struct node *reverse(struct node *first)
{
    struct node *ptr,*xptr,*nxt_ptr;
    ptr=first;
    while(ptr->next!=NULL)
    {
        nxt_ptr=ptr->next;
        xptr=ptr->next;
        ptr->next=ptr->prev;
        ptr->prev=xptr;
        ptr=nxt_ptr;
    }
    ptr->next=ptr->prev;
    ptr->prev=NULL;
    first=ptr;
    return first;
}

void display(struct node *first)
{
    struct node *ptr;
    ptr=first;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}


int main()
{
    struct node *first1=NULL;
    int ch;
    printf("You have entered into DLL program !\n");
    do{
        printf("Enter choice from 1-3 || 0 to exit\n");
        printf("1) insert 2) reverse 3) display \n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:first1=create_end_insert(first1);break;
        case 2:first1=reverse(first1);break;
        case 3:display(first1);break;
        }
    }while(ch!=0);
    return 0;
}
