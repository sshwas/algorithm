#include <cstdio>

int main()
{
   int n, inc, sum;
   char tmp;
   scanf( "%d\n", &n );
   while(n--)
   {
      inc = sum = 0;
      while((tmp = getchar()) != '\n' && tmp != EOF)
      {
         if(tmp == 'X')
            inc = 0;
         else
         {
            inc++;
            sum += inc;
         }
      }
      printf("%d\n", sum);
   }
}