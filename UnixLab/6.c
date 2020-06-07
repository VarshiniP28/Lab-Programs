#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <setjmp.h>
#include <signal.h>
jmp_buf buf;

void signal_callback_handler(int signum)
{
   printf("Caught signal %d\nInterrupt from keyboard\n",signum);
   longjmp(buf,2);
   exit(signum);
}

void signal_callback_handler1(int signum)
{
   printf("Caught signal %d\nFloating Point Exception\n",signum);
   longjmp(buf,2);
   exit(signum);
}

void signal_callback_handler2(int signum)
{
   printf("Caught signal %d\nInvalid Memory Reference\n",signum);
   longjmp(buf,2);
   exit(signum);
}

void signal_callback_handler3(int signum)
{
   printf("Caught signal %d\nChild Process stopped or terminated\n",signum);
   longjmp(buf,2);
   exit(signum);
}

void signal_callback_handler4(int signum)
{
   printf("Caught signal %d\nIllegal Instruction\n",signum);
   longjmp(buf,2);
   exit(signum);
}

int main()
{
int i=0;
if(setjmp(buf)==1)
 {
  i++;
  if(i==1)
  signal(SIGINT, signal_callback_handler);
 
  if(i==2)
  {
  signal(SIGFPE, signal_callback_handler1);
  int k;
  printf("Enter 0 to check for FPE\n");
  scanf("%d",&k);
  int i1=2/k;
  }
 
  if(i==3)
  {
  signal(SIGSEGV, signal_callback_handler2);
  char *str;  
    str = "THIS IS A STRING";      
  *(str+1) = 'n';  
  }
  
  if(i==4)
  {
  signal(SIGCHLD, signal_callback_handler3);
  int k = fork();
  if(k==0)
  {
  exit(0);
  }
  }
 
  if(i==5)
  {
  signal(SIGILL, signal_callback_handler4);
  int nityam = raise(SIGILL);
  }
  
  while(1)
  {
 printf("Program processing stuff here.\n");
 sleep(1);
  }
  }
  
else
  {
  longjmp(buf,1);
  }
   return EXIT_SUCCESS;
}
