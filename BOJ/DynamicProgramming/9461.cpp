#include <cstdio>

long long dp[101];
int main()
{
   int t, n;
   scanf("%d", &t);
   while(t--)
   {
      scanf("%d", &n);
      dp[1] = dp[2] = dp[3] = 1;
      for(int i = 4; i <= n; i++)
         dp[i] = dp[i - 3] + dp[i - 2];
      printf("%lld\n", dp[n]);
   }
   return 0;
}