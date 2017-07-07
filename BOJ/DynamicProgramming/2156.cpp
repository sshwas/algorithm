#include <cstdio>

#define MAX(a,b)  ((a)>(b) ? (a):(b))
int dp[10001], a[10001];
int main()
{
   int n;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
      scanf("%d", &a[i]);

   dp[1] = a[1], dp[2] = a[1] + a[2];
   for(int i = 3; i <= n; i++)
      dp[i] = MAX( MAX(dp[i - 1], dp[i - 2] + a[i]), dp[i-3] + a[i-1] + a[i]);

   printf("%d", dp[n]);
   return 0;
}