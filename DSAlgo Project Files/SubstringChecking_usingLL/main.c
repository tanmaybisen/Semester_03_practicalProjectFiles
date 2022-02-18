#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
}*temp;

typedef struct node node;

node *first=NULL;

node *create(node*first,int size)
{
    node *ptr;
    char i,val;
    for(i=0;i<size;i++)
    {
        printf("enter node data : ");
        getchar();
        scanf("%c",&val);
        temp=(node*)malloc(sizeof(node));
        temp->data=val;
        temp->next=NULL;
        if(first==NULL)
        {
            first=temp;
            first->next=NULL;
        }
        else
        {
            ptr=first;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
    return first;
}

void display(node *first)
{
    node *ptr;
    ptr=first;
    while(ptr!=NULL)
    {
        printf("%c ",ptr->data);
        ptr=ptr->next;
    }
    return;
}

int search_for_substring(node *first,char s[])
{
    int j=0,len=strlen(s);
    node *ptr,*ptr1;
    ptr=first;
    while(ptr!=NULL)
    {
        j=0;
        if(ptr->data==s[j])
        {
            j++;
            ptr1=ptr;
            ptr1=ptr1->next;
            while(j<len && ptr!=NULL)
            {
                if(ptr1->data!=s[j])
                    return 0;
                else
                {
                    j++;
                    ptr1=ptr1->next;
                }
            }
            if(j==len)
                return 1;
        }
        ptr=ptr->next;
    }
}

int main()
{
    int k,n,c,i;
    char s[10];
    printf("Total Char To Enter Are : ");
    scanf("%d",&n);
    first=create(first,n);
    display(first);
    printf("\nenter number of substrings to be checked\n");
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
    printf("\nenter substring to be search\n");
    scanf("%s",s);
    k=search_for_substring(first,s);
    if(k==0)
        printf("NO - NOT A SUBSTRING OF GIVEN LL\n");
    else
        printf("YES - IS A SUBSTRING OF GIVEN LL\n");
    }
    return 0;
}
