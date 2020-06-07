
#include<stdio.h>
int c[10];
int max(int a, int b) {
   if(a>b){

      return a;
   } else {

      return b;
   }
}
void knapsack(int W, int wt[], int val[], int n) 
{
   int i, w;
   int knap[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
      for (w = 0; w <= W; w++) 
      {
         if (i==0 || w==0)
          {  
           knap[i][w] = 0;
           printf("%d\t",knap[i][w]);
          }
         else if (wt[i-1] <= w)
          {  
           knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
           printf("%d\t",knap[i][w]);
          }
         else
         {
           knap[i][w] = knap[i-1][w];
           printf("%d\t",knap[i][w]);
         }
      }
      printf("\n");
    }
    printf("For capacity %d, the solution is : \n", knap[n][W]);
    int res=knap[n][W];
    w = W;
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res == knap[i - 1][w])  
            continue;        
        else 
        {           
            printf("%d   ", wt[i - 1]); 
            c[i-1]=1;         
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
     printf("%d\t",c[i]);
   //return knap[n][W];
}

int main() {
   int val[50],wt[50],W,i,n;
printf("How many items are there?\n");
scanf("%d",&n);
printf("Enter their weights\n");
for(i=0;i<n;i++)
scanf("%d",&wt[i]);
printf("Enter the values of them\n");
for(i=0;i<n;i++)
{
  scanf("%d",&val[i]);
  c[0]=0;
}
 printf("Enter the capacity of knapsack\n");
scanf("%d",&W);  
    knapsack(W, wt, val, n);
   return 0;
}
