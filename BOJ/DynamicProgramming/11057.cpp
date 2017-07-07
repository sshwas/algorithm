#include <cstdio>

const int mod = 10007;
int dp[1001][10];
int main()
{
   int n;
   scanf("%d", &n);
   for(int i = 0; i <= 9; i++)
      dp[1][i] = 1;
   for(int i = 2; i <= n; i++)
   {
      for(int j = 0; j <= 9; j++)
      {
         for(int k = 0; k <= j; k++)
         {
            dp[i][j] += dp[i - 1][k];
            dp[i][j] %= mod;
         }
      }
   }
   int ans = 0;
   for(int i = 0; i <= 9; i++)
      ans += dp[n][i];
   printf("%d", ans%mod);
   return 0;
}