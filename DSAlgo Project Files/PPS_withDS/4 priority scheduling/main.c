//        Suppose a priority queue is implemented as a sorted list.
//        Implement a program to use this queue to schedule processes according to their priority
//        (Priority Scheduling Algorithm).
//        In Priority scheduling each process is assigned a priority.
//        Processes with same priority are executed on first come first served basis.
//        Consider following set of processes and generate the sequence in which processes get executed.
//                            -------------------------------------
//                            |Process| Cpu Burst Time | Priority |
//                            |-------|----------------|----------|
//                            | P1    |       9        |   2      |
//                            | P2    |       3        |   5      |
//                            | P3    |       5        |   4      |
//                            | P4    |       2        |   3      |
//                            | P5    |       4        |   4      |
//                            | P6    |       2        |   1      |
//                            | P7    |       8        |   2      |
//                            -------------------------------------
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int process;
    int cpu_burst;
    int priority;
    struct queue *next;
}*q;

struct queue *first=NULL;

void display(struct queue *first)
{
    struct queue *ptr;
    ptr=first;
    printf("Tasks are scheduled as below: \n");
    while(ptr!=NULL)
    {
        printf("PROCESS NO. %d with priority %d with cpu-burst-time of %d\n",ptr->process,ptr->priority,ptr->cpu_burst);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}

struct queue *insert(struct queue *first)
{
    struct queue *ptr;
    int i,pri,t;
    printf("Enter total number of process : ");
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        ptr=first;
        q=(struct queue*)malloc(sizeof(struct queue));
        q->next=NULL;
        printf("Enter process no, cpu-burst-time and priority\n");
        scanf("%d%d%d",&q->process,&q->cpu_burst,&pri);
        q->priority=pri;
        if((ptr==NULL) || (pri > ptr->priority))
        {
            if(ptr==NULL)
            {
                first=q;
                first->next=NULL;
            }
            else
            {
                q->next=first;
                first=q;
            }
        }
        else
        {
            while(ptr->next!=NULL && ptr->next->priority >= pri)
            {
                ptr=ptr->next;
            }
            q->next=ptr->next;
            ptr->next=q;
        }
    }
    return first;
}

struct queue *deletor(struct queue *first)
{
    struct queue *ptr,*pre_ptr;
    int val;
    ptr=first;
    if(ptr==NULL)
    {
        printf("NO PROCESS AVAILABLE TO DELETE\n");
    }
    printf("Enter process no. to be discarded\n");
    scanf("%d",&val);
    while(ptr->process!=val)
    {
        pre_ptr=ptr;
        ptr=ptr->next;
    }
    if(first->process!=val && ptr->next!=NULL)
    {
    pre_ptr->next=ptr->next;
    }
    else if(val==first->process)
    {
        first=first->next;
    }
    else
    {
        pre_ptr->next=NULL;
    }
     return first;
}

int main()
{
    struct queue *first1=NULL;
    int ch;
    printf("YOU HAVE ENTERED A PROCESS SCHEDULING PROGRAM\n");
    do{
    printf("choose 1-3 || 0 to exit\n");
    printf("1) insert process 2)delete process 3) display schedule\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            first1=insert(first1);break;
        case 2:
            first1=deletor(first1);break;
        case 3:
            display(first1);break;
    }
    }while(ch!=0);
    return 0;
}









