#include <stdio.h>

int dp[10001], a[101];

int main()
{
   int n, i, j, k;
   scanf("%d %d", &n, &k);
   for(i = 1; i <= n; i++)
      scanf("%d", &a[i]);

   dp[0] = 1;
   for(i = 1; i <= n; i++)
      for(j = 0; j <= k; j++)
         if((j + a[i]) <= k)
            dp[j + a[i]] += dp[j];
   
   printf("%d", dp[k]);
   return 0;
}