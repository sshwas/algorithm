#include <cstdio>
#include <cstring>

int top = -1, stack[10001];
#define isEmpty() (top == -1) 
#define size() (top + 1) 

void push(int n)
{
   stack[++top] = n;
}
void pop()
{
   if(isEmpty())
      printf("-1\n");
   else
      printf("%d\n", stack[top--]);
}
void topnum()
{
   if(isEmpty())
      printf("-1\n");
   else
      printf("%d\n", stack[top]);
}

int main()
{
   int N,d;
   char cmd[6];
   scanf("%d", &N);
   while(N--)
   {
      scanf("%s", cmd);
      if(!strcmp(cmd, "push"))
      {
         scanf("%d", &d);
         push(d);
      }
      if(!strcmp(cmd, "pop"))
         pop();
      else if(!strcmp(cmd, "size"))
         printf("%d\n", size());         
      else if(!strcmp(cmd, "empty"))
         printf("%d\n", isEmpty());
      else if(!strcmp(cmd, "top"))
         topnum();
   }
}
