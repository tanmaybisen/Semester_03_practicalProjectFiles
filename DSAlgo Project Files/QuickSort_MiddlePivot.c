#include <stdio.h>
#include <conio.h>
#define size 100
void quick_sort(int A[],int beg,int end);
int main()
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
printf("\n\n\n");
quick_sort(A,0,s-1);
printf("sorted array is:\n");
for(i=0;i<6;i++)
{
    printf("%d ",A[i]);
}
printf("\n");
return 0;
}

void quick_sort(int A[],int beg,int end)
{
int loc,i,left,right,temp;
right=end;
left=beg;
loc=A[(beg+end)/2];

while(left<=right)
{
    while(A[left]<loc)
    {
        left++;
    }
    while(A[right]>loc)
    {
        right--;
    }
    if(right>=left)
    {
        temp=A[left];
        A[left]=A[right];
        A[right]=temp;
        right--;
        left++;
    }
    for(i=0;i<6;i++)
{
    printf("%d ",A[i]);
}
printf("\n");

}
    quick_sort(A,beg,right);
    quick_sort(A,left,end);
}

