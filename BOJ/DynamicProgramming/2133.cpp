#include <cstdio>

int dp[31];
int main()
{
   int n;
   scanf("%d", &n);
   dp[0] = 1, dp[2] = 3;
   for(int i = 4; i <= n; i += 2)
   {
      dp[i] = dp[i - 2] * 3;
      for(int j = 0; j <= i - 4; j += 2)
         dp[i] += 2 * dp[j];
   }
   printf("%d", dp[n]);
   return 0;
}