#include<stdio.h>

void mergesort(int b1[],int left,int right)
{
	int mid;
	if(left<right)
	{
		mid=(right+left)/2;
		mergesort(b1,left,mid);
		mergesort(b1,mid+1,right);
		merge(b1,left,mid,(mid+1),right);
	}
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
	int p2[50];
	int i=i1,j=i2,k=0;

	while(i<=j1 && j<=j2)
	{
		if(a[i]<a[j])
        {
            p2[k++]=a[i++];
        }
		else
        {
            p2[k++]=a[j++];
        }
	}

	while(i<=j1)
    {
        p2[k++]=a[i++];
    }
	while(j<=j2)
    {
        p2[k++]=a[j++];
    }


	for(i=i1,j=0;i<=j2;i++,j++)
    {
        a[i]=p2[j];
    }
}

int main()
{
	int a[20],n,i;
	printf("total elements\n");
	scanf("%d",&n);
	printf("elements\n");
	for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
	mergesort(a,0,n-1);
	printf("result/n");
	for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
	return 0;
}




