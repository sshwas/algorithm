#include <cstdio>

#define MAXVALUE    0x7fffffff
#define MAX(a,b)    (a>b?a:b)
#define MIN(a,b)    (a<b?a:b)

int dp[10001][101];
int main()
{
   int n, m, i, j, k, min;
   scanf("%d %d", &n, &m);
   for(i = 1; i <= n; i++)
   {
      for(j = 1; j <= m; j++)
      {
         if(i == j)
         {
            dp[i][j] = 1;
            continue;
         }
         if(i == 1 || j == 1)
         {
            dp[i][j] = MAX(i, j);
            continue;
         }
         if(i%j == 0)
         {
            dp[i][j] = i / j;
            continue;
         }

         min = MAXVALUE;
         if(i >= 3 * j)
            min = MIN(min, dp[i - j][j] + 1);
         else
         {
            for(k = 1; k <= i / 2; k++)
               min = MIN(min, dp[k][j] + dp[i - k][j]);
            for(k = 1; k <= j / 2; k++)
               min = MIN(min, dp[i][k] + dp[i][j - k]);
         }
         dp[i][j] = min;
      }
   }

   printf("%d\n", dp[n][m]);
   return 0;
}