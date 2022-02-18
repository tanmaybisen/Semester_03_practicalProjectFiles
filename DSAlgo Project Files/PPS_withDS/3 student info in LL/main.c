//    Consider you have to store information about the student like
//    Name, Enrollment number, SGPA of 3 Semesters and CGPA.
//    Store this information in a single linked list.
//    Perform the following operations on linked list and display the result.

//    1) Insert the information about new student
//    2) Delete the information of a student where Enrollment number is specified
//    3) Update SGPA or Name of Student when Enrollment number is specified
//    4) Calculate CGPA of each student
//    5) Find the Class Topper according to CGPA
//    6) Display the result of all students

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[10];
    int enroll_no;
    float sgpa[3];
    float cgpa;
    struct node *next;
}*q,*p,*r;

struct node *first1=NULL;

struct node *create(struct node *first)
{
    struct node *ptr,*q;
    int i,en,total;
    float sg1,sg2,sg3;
    printf("Enter total no. of students: ");
    scanf("%d",&total);
    for(i=0;i<total;i++)
    {
        q = (struct node*)malloc(sizeof(struct node));
        q->next=NULL;
        printf("Enter FIRST name of student : ");
        scanf("%s",q->name);
        printf("Enter enrollment number : ");
        scanf("%d",&en);
        q->enroll_no=en;
        printf("Enter sgpa of 3 semesters : \n");
        scanf("%f%f%f",&sg1,&sg2,&sg3);
        q->sgpa[0]=sg1;
        q->sgpa[1]=sg2;
        q->sgpa[2]=sg3;
        ptr=first;
        if(ptr==NULL)
        {
            first=q;
            first->next=NULL;
        }
        else
        {
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

struct node *delete_node(struct node *first)
{
    struct node *ptr,*pre_ptr;
    int en_val;
    ptr=first;
    printf("Specify the enrollment no. of student whose info. is to be deleted : \n");
    scanf("%d",&en_val);


    while(ptr!=NULL)
    {
        if(ptr->enroll_no!=en_val)
        {
            pre_ptr=ptr;
            ptr=ptr->next;
        }
        else
        {
            if(ptr==first)
            {
                first=ptr->next;return first;
            }
            else if(ptr->next==NULL)
            {
                printf("condition reached \n");
                pre_ptr->next=NULL;free(ptr);
                return first;
            }
            else
            {
                pre_ptr->next=ptr->next;return first;
            }
        }
}

    if(ptr==NULL)
    {
        printf("student is not enrolled : \n");
    }
    return first;
}

struct node *sgpa_name_update(struct node *first)
{
    struct node *ptr;
    int enrol,up,sem;
    float up_s;
    printf("Enter enrollment no. of student whose info is to be updated  ");
    scanf("%d",&enrol);
    ptr=first;
    while(ptr->enroll_no!=enrol)
    {
        ptr=ptr->next;
    }
    do{
    printf("What you wish to update : [ (0) STOP UPDATING ] (1) Name (2) SGPA \n");
    scanf("%d",&up);
    if(up==1)
    {
        printf("Enter new name : ");
        scanf("%s",ptr->name);
    }
    else if(up==2)
    {
        printf("Enter which semester sgpa you wish to edit : ");
        scanf("%d",&sem);
        switch(sem)
        {
        case 1:
            printf("Update sgpa value of sem 1 to : ");
            scanf("%f",&up_s);
            ptr->sgpa[0]=up_s;break;
        case 2:
            printf("Update sgpa value of sem 2 to : ");
            scanf("%f",&up_s);
            ptr->sgpa[1]=up_s;break;
        case 3:
            printf("Update sgpa value of sem 3 to : ");
            scanf("%f",&up_s);
            ptr->sgpa[2]=up_s;break;
        }
        ptr->cgpa=((ptr->sgpa[0]+ptr->sgpa[1]+ptr->sgpa[2])/(3));
    }
    }while(up!=0);
    return first;

}

struct node *cgpa_cal(struct node *first)
{
    struct node *ptr;
    ptr=first;
    while(ptr!=NULL)
    {
        ptr->cgpa=((ptr->sgpa[0]+ptr->sgpa[1]+ptr->sgpa[2])/(3));
        printf("\tCgpa of Mast/Miss %s is %f.\n",ptr->name,ptr->cgpa);
        ptr=ptr->next;
    }
    printf("\n");
    return first;
}

void display(struct node *first)
{
    struct node *ptr;
    first=cgpa_cal(first);
    ptr=first;
    while(ptr!=NULL)
    {
        printf("First name : ");
        puts(ptr->name);
        printf("\tEnroll No.: %d \n\tSGPA sem 1: %f sem 2: %f sem 3: %f \n\tCGPA : %f\n",ptr->enroll_no,ptr->sgpa[0],ptr->sgpa[1],ptr->sgpa[2],ptr->cgpa);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}

struct node *topper_finder(struct node *first)
{
    struct node *ptr;
    int large;
    first=cgpa_cal(first);
    ptr=first;
    large=ptr->cgpa;
    while(ptr!=NULL)
    {
        if(ptr->cgpa > large)
        {
            large=ptr->cgpa;
        }
        ptr=ptr->next;
    }
    ptr=first;
    while(ptr->cgpa!=large)
    {
        ptr=ptr->next;
    }
    printf("\t______TOPPER INFO______\n");
    printf("\tName : %s .\n\tSGPA sem 1 : %f , sem 2 : %f , sem 3 : %f .\n\tCGPA %f .\n\n",ptr->name,ptr->sgpa[0],ptr->sgpa[1],ptr->sgpa[2],ptr->cgpa);
    return first;
}
int main()
{
    int chosen;
    first1=create(first1);
    do{
        printf("________Choose from  1-6 || 0 to exit________\n");
        printf("1) Insert the information about new student\n");
        printf("2) Delete the information of a student\n");
        printf("3) Update SGPA or Name of Student\n");
        printf("4) Calculate CGPA of each student\n");
        printf("5) Find the Class Topper according to CGPA\n");
        printf("6) Display the result of all students\n");
        scanf("%d",&chosen);
        switch(chosen)
        {
        case 1:
            first1=create(first1);break;
        case 2:
            first1=delete_node(first1);break;
        case 3:
            first1=sgpa_name_update(first1);break;
        case 4:
            first1=cgpa_cal(first1);break;
        case 5:
            first1=topper_finder(first1);break;
        case 6:
            display(first1);break;
        }
    }while(chosen!=0);
    printf("\n\n:-) pleasue giving service\n\n");
    return 0;
}
