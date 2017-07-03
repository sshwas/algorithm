#include <stdio.h>

long long dp[101][101][101];
int main()
{
   int N, L, R, i, j, k;
   scanf("%d %d %d", &N, &L, &R);

   dp[1][1][1] = 1LL;
   for(i = 2; i <= N; i++)
      for(j = 1; j <= L; j++)
         for(k = 1; k <= R; k++)
            if(i >= j && i >= k)
            {
               dp[i][j][k] += dp[i - 1][j - 1][k];
               dp[i][j][k] += dp[i - 1][j][k - 1];
               dp[i][j][k] += (dp[i - 1][j][k] * (i - 2));
               dp[i][j][k] %= 1000000007;
            }

   printf("%lld", dp[N][L][R]);
   return 0;
}