// Parenthesis String

#include <cstdio>

int main()
{
   int n, top;
   char tmp, chk = 0;
   scanf("%d\n", &n);
   while(n--)
   {
      top = -1; chk = 0;
      while((tmp = getchar()) != '\n')
      {
         if(tmp == '(')
            top++;
         else if(tmp == ')')
         {
            top--;
            if(top < -1)
               chk = 1;
         }
      }
      printf("%s\n", (((top == -1) && (chk != 1)) ? "YES" : "NO"));
   }
}