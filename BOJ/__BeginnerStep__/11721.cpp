#include <cstdio>

int main()
{
   int n=0;
   char str[101];
   scanf("%s", str);
   while(str[n]!='\0')
   {
      if((n % 10) || !n)
         printf("%c", str[n++]);
      else
      {
         printf("\n%c", str[n++]);
      }
   }
}