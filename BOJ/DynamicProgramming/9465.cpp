#include <cstdio>

#define MAX(a,b)  ((a)>(b) ? (a):(b))
int dp[100001][3], a[100001][2];
int main()
{
   int t, n;
   scanf("%d", &t);
   while(t--)
   {
      scanf("%d", &n);
      int i;
      for(i = 1; i <= n; i++)
         scanf("%d", &a[i][0]);
      for(i = 1; i <= n; i++)
         scanf("%d", &a[i][1]);

      // dp[i][0] = not selected, dp[i][1] = first one, dp[i][2] = second one.
      for(i = 1; i <= n; i++)
      {
         dp[i][0] = MAX( MAX(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
         dp[i][1] = MAX(dp[i - 1][0], dp[i - 1][2]) + a[i][0];
         dp[i][2] = MAX(dp[i - 1][0], dp[i - 1][1]) + a[i][1];
      }
      printf("%d\n", MAX( MAX(dp[n][0], dp[n][1]), dp[n][2]) );
   }
   return 0;
}