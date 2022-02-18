#include <stdio.h>
#include <conio.h>
#define size 100
int partition(int A[],int beg,int end);
void quick_sort(int A[],int beg,int end);
void main()
{
int A[6]={27,10,36,18,25,45},i,s=6;
printf("enter the size of the array to be sorted using quick sort\n");
//scanf("%d",&s);
//for(i=0;i<s;i++)
//{
//    printf("enter element %d : ",i+1);
//    scanf("%d",&A[i]);
//}
for(i=0;i<6;i++)
{
    printf("%d ",A[i]);
}
printf("\n");
quick_sort(A,0,s-1);
printf("sorted array is:\n");
for(i=0;i<6;i++)
{
    printf("%d ",A[i]);
}
getch();
}


int partition(int A[],int beg,int end)
{
int loc,left,right,flag=0,temp;
left=beg;
right=end;
loc=left;
while(flag!=1)
{
while((A[loc]<=A[right]) && (loc!=right))
{
    right=right-1;
}
if(loc==right)
{
    flag=1;
}
else
    {
        if(A[loc]>A[right])
        {
          temp=A[loc];
          A[loc]=A[right];
          A[right]=temp;
          loc=right;
        }
    }
}
//hey this is the next part
if(flag==0)
{
while((A[loc]>=A[left]) && (loc!=left))
{
    left=left+1;
}
if(loc==left)
{
    flag=1;
}
else
    {
        if(A[loc]<A[left])
        {
          temp=A[loc];
          A[loc]=A[left];
          A[left]=temp;
          loc=left;
        }
    }

}
return loc;
}

void quick_sort(int A[],int beg,int end)
{int loc;
if(beg<end)
    {
    loc=partition(A,beg,end);
    quick_sort(A,beg,loc-1);
    quick_sort(A,loc+1,end);
    }
}

