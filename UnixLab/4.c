#include<stdio.h>
#include<setjmp.h>
jmp_buf buf;
jmp_buf buf1;
int fun1()
{
  printf("Entered the function 1\n");
  longjmp(buf1,10);
  printf("This statement will not work");
}

int fun2()
{
  printf("Entered the function 2\n");
  longjmp(buf,20);
  printf("This statement will not work");
}

int main()
{
  int n=setjmp(buf);
  printf("Starting the program\n");
  n=setjmp(buf1);
  printf("In main function\n");
  if(n==0)
  {
    fun1();
  }
  if(n==10)
  {
    printf("Exited function 1\n");
    fun2();
  }
  if(n==20)
  {
    printf("Exited function 2\n");
  }
  printf("Exiting main function\n");
}
