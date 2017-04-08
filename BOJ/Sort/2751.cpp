// Counting sort
#include <cstdio>

int main()
{
   int N, i, tmp;
   char arr[20000001];

   scanf("%d", &N);
   while(N--)
   {
      scanf("%d", &tmp);
      arr[tmp + 1000000] = 1;
   }
   for(i = 0; i < 2000001; i++)
   {
      if(arr[i])
      {
         printf("%d\n", (i - 1000000));
      }
   }
}