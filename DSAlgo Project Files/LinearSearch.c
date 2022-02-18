#include<stdio.h>

int linear_s(int a[100] ,int n)
{
int val,i;
printf("\nwhat element do you want to search?");
scanf("%d",&val);
for(i=0;i<n;i++)
{
	if (val==a[i])
		return 1;
}
return 0;
}

int main()
{
	int a[100],n;
	printf("\t\tLINEAR SEARCH");
	int i,flag;
	printf("\nHow many values do you want in your array");
	scanf("%d",&n);
	printf("\nstart filling the array");

	for(i=0;i<n;i++)                                                   //feeding elements
		{
			printf("\nElement %d",i+1);
			scanf("%d",&a[i]);
		}

flag=linear_s(a,n);
if(flag==1)
printf("\n ELEMENT FOUND!");
else
printf("\n ELEMENT NOT FOUND!");

return 0;
}


