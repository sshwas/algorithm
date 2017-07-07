#include <cstdio>

const long long mod = 1000000000;
long long dp[101][10];
int main()
{
   int n;
   scanf("%d", &n);
   for(int i = 1; i <= 9; i++)
      dp[1][i] = 1;
   for(int i = 2; i <= n; i++)
   {
      for(int j = 0; j <= 9; j++)
      {
         if(j >= 1)
            dp[i][j] += dp[i - 1][j - 1];
         if(j <= 8)
            dp[i][j] += dp[i - 1][j + 1];
         dp[i][j] %= mod;
      }
   }
   long long ans = 0;
   for(int i = 0; i <= 9; i++)
      ans += dp[n][i];
   printf("%d", ans%mod);
   return 0;
}