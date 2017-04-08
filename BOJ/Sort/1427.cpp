// Bubble sort
#include <cstdio>

int main()
{
   int N = 0, i, j, tmp;
   char num[10];

   while((num[N] = getchar()) != '\n')
   {
      N++;
   }
   for(i = 0; i < N - 1; i++)
   {
      for(j = 0; j < N - 1 - i; j++)
      {
         if(num[j]<num[j + 1])
         {
            tmp = num[j];
            num[j] = num[j + 1];
            num[j + 1] = tmp;
         }
      }
   }
   for(i = 0; i < N; i++)
      printf("%c", num[i]);
}

