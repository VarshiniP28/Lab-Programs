#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 500
int t[MAX];
static int count=0;
void shifttable(char p[])
{
 int i,j,m;
 m=strlen(p);
 for(i=0;i<MAX;i++)
  t[i]=m;
  printf("Table --\n");
 for(j=0;j<m-1;j++){
  t[p[j]]=m-1-j;
  printf("%c -- %d\n",p[j],t[p[j]]);}
  printf("* -- %d\n",t[p[j+1]]);
}
int horspool(char src[],char p[])
{
 int i,j,k,m,n;
 n=strlen(src);
 m=strlen(p);
 printf("\nLength of text=%d",n);
 printf("\nLength of pattern=%d",m);
 i=m-1;
 while(i<n)
 {count++;
  k=0;
  while((k<m)&&(p[m-1-k]==src[i-k])){//Check the string
   k++; count++; }
  if(k==m)//End of substring
   return(i-m+1);
  else
   i+=t[src[i]];//Shift the characters according the the bad match table
 }
 return -1;
 }
 
void main()
{
 char src[100],p[100];
 int pos;
 printf("Enter the text in which pattern is to be searched:\n");
 gets(src);
 printf("Enter the pattern to be searched:\n");
 gets(p);
 shifttable(p);
 pos=horspool(src,p);
 if(pos>=0)
  printf("\nThe desired pattern was found starting from position %d\n",pos+1);
 else
  printf("\nThe pattern was not found in the given text\n");
 
}
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
