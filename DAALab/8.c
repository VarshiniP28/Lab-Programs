
//Write a program to find Minimum cost spanning tree of a given undirected graph using Prim’salgorithm.


#include<stdio.h>
#define INFINITY 999

void prims(int n,int cost[10][10],int source)
{
 int v[10]; 
 int d[10]; 
 int i, j; 
 int vertex[10]; 
 int u, least, sum=0;

 for(i=1;i<=n;i++)
 {
  v[i] = 0; //used to keep check whether all nodes are reached
  d[i] = cost[source][i]; 
  vertex[i] = source; 
 }
 v[source] = 1; 

 for(i=1;i<n;i++)
 {
  least = INFINITY;
  for(j=1; j<=n; j++)
  {
   if(v[j] == 0 && d[j] < least)
   {
    least = d[j];
    u = j;
   }
  }
  v[u] = 1;
  sum += d[u];
  printf("%d --> %d = %d Sum = %d\n\n",vertex[u],u,d[u],sum);

  for(j=1;j<=n;j++)
  {
   if(v[j] == 0 && cost[u][j] < d[j])
   {
    d[j] = cost[u][j];
    vertex[j] = u;
   }
  }
 }
 printf("Total cost: %d",sum);
}

int main()
{
 int n; 
 int cost[10][10]; 
 int source; 
 int i, j; 
 printf("Enter n (no. of nodes): ");
 scanf("%d", &n);
 printf("Enter cost matrix:\n ");
 for(i=1; i<=n; i++)
  for(j=1; j<=n; j++)
   scanf("%d", &cost[i][j]);
 printf("Enter Source: ");
 scanf("%d", &source);
 prims(n, cost, source);
 return 0;
}
