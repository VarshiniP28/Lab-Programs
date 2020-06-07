#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void print(int[],int);
int heapsort(int[],int);
void swap(int*,int*);
void heapify(int[],int,int);
static int count=0;
int main()
{
 int arr[100],n;
 int a[10],d[10],r[10];
 int c1,c2,c3;
 printf("Enter the number of elements in array:\t");
 scanf("%d",&n);
 printf("Enter the elements:\n");
 for(int i=0;i<n;i++)
  scanf("%d",&arr[i]);
 printf("The unsorted array is:\t");
 print(arr,n);
 heapsort(arr,n);
 printf("\nThe sorted array is:\t");
 print(arr,n);
 printf("\n");
 printf("Count variable : %d\n\n",count);
 
 printf("\nNo. of elements\tAscendingorder\t\tDescendingorder\t\tRandomorder\n");
	printf("\t\tt1(n)\tg1(n)\t\tt2(n)\tg2(n)\t\tt3(n)\tg3(n)\n");
	for(int i=16;i<=256;i*=2)
	{
		for(int j=0;j<=i;j++)
		{
			a[j]=j;
			d[j]=i-j;
			r[j]=rand()%i;
		}
	heapsort(a,i);
	c1=count; int g1=i*log(i)/log(2);
	count=0;
	heapsort(d,i);
	c2=count; int g2=i*log(i)/log(2);
	count=0;
	heapsort(r,i);
	c3=count; int g3=i*log(i)/log(2);
	count=0;
	printf("%d\t\t%d\t%d\t\t%d\t%d\t\t%d\t%d\n",i,c1,g1,c2,g2,c3,g3);
	}
 exit(0);
}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
}
void heapify(int arr[], int n, int i)
{
    
    int p = i;
    int lc = 2*i + 1;
    int rc = 2*i + 2;
  if (lc < n && arr[lc] > arr[p]) {
        p = lc; count++;}
  if (rc < n && arr[rc] > arr[p]) {
        p = rc; count++;}
  if (p != i)
    {
        swap(&arr[i], &arr[p]);
        heapify(arr, n, p);
    }
}
int heapsort(int arr[], int n)
{
  int c1;
  for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  for (int i=n-1; i>=0; i--)
  {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
  }
    return c1;
}
void swap(int *i,int *j)
{
int temp;
temp= *i;
*i=*j;
*j=temp;
}

