#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 15
int count=0;

void printing_func(int Arr[],int value)
{
	for(int i=0;i <= value; i++)
    {
    printf("%d ",Arr[i]);
	}
	printf("\n");
}

void swaping_func(int Arr[], int p, int q)
{
	int temp_val;
	temp_val = Arr[p];
	Arr[p] = Arr[q];
	Arr[q] = temp_val;
}

void quick_sort(int a[], int left_ptr, int right_ptr)
{
	int left, right, pivot;
	if(left_ptr >= right_ptr)
    {
        return;
    }

	left = left_ptr;
	right = right_ptr;

        // pivot selection
	pivot = a[(left_ptr + right_ptr) /2];

        // partition
	while(left <= right)
    {
		while(a[left] < pivot)
		{count++;
		    left++;
		}
		while(a[right] > pivot)
        {count++;
            right--;
        }
		if(left <= right)
        {
			swaping_func(a,left,right);
			left++; right--;
		}
		//printf("UNDER PROCESS : \n");
		//print(a,right_index);
	}

        // recursion
        //printf("in process comp : %d\n",count);
	quick_sort(a,left_ptr,right);
	quick_sort(a,left,right_ptr);
}

int main()
{
	int a[SIZE],i,k;
	printf("ENTER TOTAL NO. OF ELEMENTS\n");
	scanf("%d",&k);
	printf("ENTER ELEMENTS\n");
	for(i=0;i<k;i++)
    {
    printf("Enter element %d : ",i+1);
    scanf("%d",&a[i]);
    }
	printf("\nGIVEN ORDER : \n");
	printing_func(a,k-1);
	quick_sort(a,0,k-1);
	printf("\n\nFINAL ORDER : \n");
	printing_func(a,k-1);
	printf("\n\ncomplexity is  : %d\n",count);
}
