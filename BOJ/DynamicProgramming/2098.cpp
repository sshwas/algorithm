#include <cstdio>

#define MIN(a,b)  ((a)<(b) ? (a):(b))

const int MXN = 16, inf = 987654321;
int w[MXN+1][MXN+1], dp[1 << MXN][MXN + 1];  // dp[bit state][last visited city]
int main()
{
   int n;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
         scanf("%d", &w[i][j]);

   for(int i =2; i<=(1 << n)-1; i++)
      for(int j = 1; j<=n; j++)
         dp[i][j] = inf;

   for(int i = 2; i <= n; i++)
      dp[1 << (i - 1)][i] = w[1][i];

   for(int i = 2; i <= (1 << n)-1; i++)
      for(int j = 2; j <= n; j++)
         if(i & (1 << (j - 1)))
            for(int k = 2; k <= n; k++)
               if( k != j && (i & (1<<(k - 1))) && w[k][j] )
                  dp[i][j] = MIN(dp[i][j], dp[i & ~(1 << (j - 1))][k] + w[k][j]);

   int ans = inf;
   for(int i = 2; i<= n; i++)
      if(w[i][1])
         ans = MIN(ans, dp[(1 << n)-2][i] + w[i][1]);

   printf("%d", ans);
   return 0;
}