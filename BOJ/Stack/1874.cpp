#include <cstdio>

int top, stack[100001];
char res[200002];

void push(int n)
{
   stack[++top] = n;
}
int pop()
{
   return stack[top--];
}

int main()
{
   int n,t,i=1,j=0;
   scanf("%d", &n);
   while(n--)
   {
      scanf("%d", &t);
      if(stack[top] < t)
      {
         while(stack[top] < t)
         {
            push(i++);
            res[j++] = '+';
         }
      }
      if(stack[top] == t)
      {
         pop();
         res[j++] = '-';
      }
      else
         break;
   }
   if(stack[top])
      printf("NO");
   else
   {
      for(n = 0; n < j; n++)
         printf("%c\n", res[n]);
   }
}