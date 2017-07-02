#include <cstdio>

long long dp[111][111];
int a[101][101];
int main()
{
   int N, i, j;
   scanf("%d", &N);
   for(i = 1; i <= N; i++)
      for(j = 1; j <= N; j++)
         scanf("%d", &a[i][j]);

   dp[1][1] = 1;
   for(i = 1; i <= N; i++)
   {
      for(j = 1; j <= N; j++)
      {
         if(a[i][j] == 0)
            continue;
         dp[i + a[i][j]][j] += dp[i][j];
         dp[i][j + a[i][j]] += dp[i][j];
      }
   }
   printf("%lld", dp[N][N]);
   return 0;
}