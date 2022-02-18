//sort elements of singly linked lists and circular linked lists
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*p;

struct node *first1=NULL,*first=NULL;

struct node *create(struct node *first,int num)
{
    struct node *ptr;
    int value,i;
    printf("Enter max size of list\n");
    scanf("%d",&value);
    for(i=0;i<value;i++)
    {
        ptr=first;
        p=(struct node*)malloc(sizeof(struct node));
        p->next=NULL;
        printf("Enter the value to be inserted \n");
        scanf("%d",&p->data);
        if(ptr==NULL)
        {
            first=p;
            if(num==1)
            {
                first->next=NULL;
            }
            else if(num==2)
            {
                first->next=first;
            }

        }
        else
        {
            ptr=first;
            if(num==1)
            {
               while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=p;
                p->next=NULL;
            }
            else if(num==2)
            {
                while(ptr->next!=first)
                {
                    ptr=ptr->next;
                }
                ptr->next=p;
                p->next=first;
            }

        }
    }
    return first;
}


struct node *display(struct node *first,int val)
{
    struct node *ptr;
    if(val==1)
    {
        ptr=first;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    else if(val==2)
    {
        ptr=first;
        do{
            printf("%d ",ptr->data);
            ptr=ptr->next;
        } while(ptr!=first);
        printf("\n");
    }
    return first;

}

struct node *any_sort(struct node *first)
{
    int temp;
    struct node *ptr,*nxt_ptr;
    ptr=first;
    do{
            nxt_ptr=ptr->next;
            while(nxt_ptr!=first && nxt_ptr!=NULL)
            {
                if(ptr->data > nxt_ptr->data)
                {
                    temp=ptr->data;
                    ptr->data=nxt_ptr->data;
                    nxt_ptr->data=temp;
                }
                nxt_ptr=nxt_ptr->next;
            }
            ptr=ptr->next;
    }while(ptr!=first && ptr!=NULL);

return first;
}

int main()
{
    int choice;
    printf("You wish to create which type of linked list ?\n\t1) singly linked\n\t2) circular linked\n");
    scanf("%d",&choice);
    first1=create(first1,choice);
    printf("Entered linked lits was : \n");
    display(first1,choice);
    printf("Sorted linked lits is : \n");
    first1=any_sort(first1);
    display(first1,choice);
    return 0;
}

