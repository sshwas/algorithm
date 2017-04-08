// Counting sort
#include <cstdio>

int arr[10001];
int main()
{
   int N, i, j, tmp;
   scanf("%d", &N);
   while(N--)
   {
      scanf("%d", &tmp);
      arr[tmp]++;
   }
   for(i = 0; i < 10001; i++)
   {
      for(j = 0; j < arr[i]; j++)
      {
         printf("%d\n", i);
      }
   }
}