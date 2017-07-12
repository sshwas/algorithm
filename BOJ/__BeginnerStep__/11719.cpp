#include <cstdio>

char str[101];

int main()
{
   int i=0;
   char tmp;
   while((tmp = getchar()) != EOF)
   {
      if(tmp == '\n')
      {
         str[i] = '\0';
         printf("%s\n", str);
         i = 0;
      }
      else
         str[i++] = tmp;
   }
}