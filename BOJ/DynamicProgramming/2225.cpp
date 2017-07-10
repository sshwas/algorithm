#include <cstdio>

const int mod = 1000000000;
long long dp[201][201];
int main()
{
   int n, k;
   scanf("%d %d", &n, &k);
   dp[0][0] = 1LL;
   for(int i = 1; i <= k; i++)
   {
      for(int j = 0; j <= n; j++)
      {
         for(int l = 0; l <= j; l++)
         {
            dp[j][i] += dp[j - l][i - 1];
            dp[j][i] %= mod;
         }
      }
   }
   printf("%lld", dp[n][k]);
   return 0;
}