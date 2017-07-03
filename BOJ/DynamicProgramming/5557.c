#include <stdio.h>

#define MAX_VAL  20
long long dp[101][MAX_VAL+1], a[101];

int main()
{
   int N, i, j, ans = 0;
   scanf("%d", &N);

   for(i = 1; i <= N; i++)
      scanf("%d", &a[i]);

   // assign the number of calculation paths for the all of possible cases 
   dp[1][a[1]] = 1;
   for(i = 2; i < N; i++)
   {
      for(j = 0; j <= MAX_VAL; j++)
      {
         if(dp[i - 1][j])
         {
            if(j - a[i] >= 0)
               dp[i][j - a[i]] += dp[i - 1][j];
            if(j + a[i] <= MAX_VAL)
               dp[i][j + a[i]] += dp[i - 1][j];
         }
      }
   }
   printf("%lld", dp[N-1][a[N]]);
   return 0;
}