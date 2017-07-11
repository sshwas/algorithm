#include <cstdio>
#define MAX(a,b)  ((a)>(b) ? (a):(b))
const int inf = 10000000;
int a[50], dp[50][250001], n;

int go(int k, int diff)
{
   if(diff > 250000)
      return -inf;
   if(k == n)
   {
      if(diff == 0)
         return 0;
      else
         return -inf;
   }
   if(dp[k][diff] != -1)
      return dp[k][diff];
   dp[k][diff] = go(k + 1, diff);
   dp[k][diff] = MAX(dp[k][diff], go(k + 1, diff + a[k]));
   if(a[k] > diff)
      dp[k][diff] = MAX(dp[k][diff], diff + go(k + 1, a[k] - diff));
   else
      dp[k][diff] = MAX(dp[k][diff], a[k] + go(k + 1, diff - a[k]));
   return dp[k][diff];
}

int main()
{
   scanf("%d", &n);
   for(int i = 0; i<n; i++)
      scanf("%d", &a[i]);
   for(int i = 0; i < 50; i++)
      for(int j = 0; j < 250001; j++)
         dp[i][j] = -1;
   
   int ans = go(0, 0);
   printf("%d", (ans ? ans : -1));
   return 0;
}