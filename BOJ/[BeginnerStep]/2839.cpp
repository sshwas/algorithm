#include <cstdio>

int main()
{
   int N, a3 = 0, b5 = 0, i;

   scanf("%d", &N);
   for(i = (N / 5); i >= 0; i--)
   {
      if((N - (i * 5)) % 3 == 0)
      {
         a3 = i;
         b5 = (N - (i * 5)) / 3;
         break;
      }
   }
   printf("%d", (a3 == 0 && b5 == 0) ? (-1) : (a3 + b5));
}