/* C implementation QuickSort */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void table();
static int count=0;

int partition (int a[], int low, int high) 
{ 

	int i,j,pivot,temp;

	i=low+1;
	j=high;
	pivot=a[low];
	while(1)
	{
		while (pivot>=a[i] && i<high)
		{
			i++;
			count++;
		}
		while (pivot<a[j])
		{ 
			j--;
			count++;
		}
		count++;
		if (i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[low];
			a[low]=a[j];
			a[j]=temp;
			return j;
		}
	}
} 

// The main function that implements QuickSort 

void quickSort(int arr[], int low, int high) 
{       count++;
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 


void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int main() 
{ 
	int arr[20]; 
	int i=0,n;
        printf("Enter the number of elements in array:\t");
        scanf("%d",&n);
        printf("Enter the elements:\n");
        for(int i=0;i<n;i++)
          scanf("%d",&arr[i]);
  
        printf("\n\n");    
	 
	quickSort(arr, 0, n-1); 
	printf("Sorted array: "); 
	printArray(arr, n); 
        printf("Count variable : %d",count);
        table();
	return 0; 
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
	quickSort(a,0,i-1);
	c1=count; int g1=i*i;
	count=0;
	quickSort(d,0,i-1);
	c2=count; int g2=i*i;
	count=0;
	quickSort(r,0,i-1);
	c3=count; int g3=i*log(i)/log(2);
	count=0;
	printf("%d\t\t%d\t%d\t\t%d\t%d\t\t%d\t%d\n",i,c1,g1,c2,g2,c3,g3);
	}
        exit(0);
}
