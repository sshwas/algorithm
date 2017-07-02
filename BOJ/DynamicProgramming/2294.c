#include <stdio.h>

int dp[10001], a[101];

int main()
{
   int n, i, j, k;
   scanf("%d %d", &n, &k);
   for(i = 1; i <= n; i++)
      scanf("%d", &a[i]);
   for(i = 1; i <= k; i++)
      dp[i] = -1;

   dp[0] = 0;
   for(i = 1; i <= n; i++)
      for(j = 0; j <= k; j++)
         if((j + a[i]) <= k && dp[j] != -1)
            if(dp[j + a[i]] == -1 || dp[j + a[i]] > (dp[j] + 1))
               dp[j + a[i]] = dp[j] + 1;

   printf("%d", dp[k]);
   return 0;
}