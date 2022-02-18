#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int expo;
    struct node *next;
}*p,*r,*t;

struct node *ptr1,*ptr2,*ptr3,*first1=NULL,*first2=NULL,*first3=NULL;

void display(struct node *first)
{
    struct node *ptr;
    ptr=first;
    while(ptr!=NULL)
    {
        printf("+ %dX^%d ",ptr->coef,ptr->expo);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}

struct node *create(struct node *first)
{
    struct node *ptr,*q;
    int cof,deg,i,terms;
    printf("Enter total no. of terms of polynomial : ");
    scanf("%d",&terms);
    for(i=0;i<terms;i++)
    {
        printf("Enter coefficient and degree of term %d: \n",i+1);
        scanf("%d%d",&cof,&deg);
        q=(struct node*)malloc(sizeof(struct node));
        q->coef=cof;
        q->expo=deg;
        q->next=NULL;
        ptr=first;
        if(ptr==NULL)
        {
            first=q;
            first->next=NULL;
        }
        else{
            ptr=first;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=q;
            q->next=NULL;
        }
    }
    return first;
}

struct node *poly_adder(struct node *f1, struct node *f2)
{
    ptr1=f1;
    ptr2=f2;
    ptr3=first3;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->next=NULL;
        if(ptr1->expo==ptr2->expo)
        {

            p->coef=(ptr1->coef)+(ptr2->coef);
            p->expo=ptr1->expo;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            p->coef=ptr1->coef;
            p->expo=ptr1->expo;
            ptr1=ptr1->next;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            p->coef=ptr2->coef;
            p->expo=ptr2->expo;
            ptr2=ptr2->next;
        }
        if(ptr3==NULL)
        {
            ptr3=p;
            first3=p;
        }
        else
        {
            ptr3->next=p;
            ptr3=p;
        }
    }
    while(ptr1!=NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->coef=ptr1->coef;
        p->expo=ptr1->expo;
        p->next=NULL;
        ptr3->next=p;
        ptr3=p;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->coef=ptr2->coef;
        p->expo=ptr2->expo;
        p->next=NULL;
        ptr3->next=p;
        ptr3=p;
        ptr2=ptr2->next;
    }
    return first3;
}


int main()
{
    first1=create(first1);
    first2=create(first2);
    printf("\n");
    printf("POLYNOMIAL 1 IS : \n");
    display(first1);
    printf("\n");
    printf("POLYNOMIAL 2 IS : \n");
    display(first2);
    printf("\n");
    printf("POLYNOMIAL ADDITION RESULTS : \n");
    first3=poly_adder(first1,first2);
    display(first3);
}
