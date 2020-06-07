#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int b[50],count=0;
void merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=low;

	while(i<=mid && j<=high){
		count++;
		if(a[i]>a[j])
			b[k++]=a[j++];
		else
			b[k++]=a[i++];
	}

	for(;i<=mid;i++){
		count++;
		b[k++]=a[i];
	}

	for(;j<=high;j++){
		count++;
		b[k++]=a[j];
	}

	for(i=0;i<=high;i++)
		a[i]=b[i];
}

void mergeSort(int a[],int low,int high)
{
	int mid;
	if(low<high)
        {
		mid=(low+high)/2;
		mergeSort(a,low,mid);
		mergeSort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

void table()
{
	int i,j,a[50],d[50],r[50],c1,c2,c3;
	printf("\nNo. of elements\tAscendingorder\t\tDescendingorder\t\tRandomorder\n");
	printf("\t\tt1(n)\tg1(n)\t\tt2(n)\tg2(n)\t\tt3(n)\tg3(n)\n");
	for(i=16;i<=256;i*=2)
	{
		for(j=0;j<=i;j++)
		{
			a[j]=j;
			d[j]=i-j;
			r[j]=rand()%i;
		}
        count =0;
	mergeSort(a,0,i-1);
	c1=count; int g1=i*log(i)/log(2);
	count=0;
	mergeSort(d,0,i-1);
	c2=count; int g2=i*log(i)/log(2);
	count=0;
	mergeSort(r,0,i-1);
	c3=count; int g3=i*log(i)/log(2);
	count=0;
	printf("%d\t\t%d\t%d\t\t%d\t%d\t\t%d\t%d\n",i,c1,g1,c2,g2,c3,g3);
	}
        exit(0);
}

void main()
{
	int a[50],i,n;

	printf("\nEnter the size of array :");
	scanf("%d",&n);

	printf("\nEnter the array elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	mergeSort(a,0,n-1);

	printf("\nThe Sorted array is :");

	for(i=0;i<n;i++)
		printf("\t%d",a[i]);

	printf("\nThe count is : %d",count);
        table();
}

