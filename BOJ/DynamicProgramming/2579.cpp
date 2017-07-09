#include <cstdio>

#define MAX(a,b)  ((a)>(b) ? (a):(b))
const int MXN = 300;
int a[MXN + 1], dp[MXN + 1][2];
int main()
{
   int n;
   scanf("%d", &n);
   scanf("%d", &a[1]);
   dp[1][1] = a[1];  // dp[1][0] = 0
   if (n > 1)
   {
      scanf("%d", &a[2]);
      dp[2][0] = a[1], dp[2][1] = a[1] + a[2];
   }
   for (int i = 3; i <= n; i++)
   {
      scanf("%d", &a[i]);
      dp[i][0] = MAX(dp[i - 2][0] + a[i - 1], dp[i-3][0] + a[i-2] + a[i-1]);
      dp[i][1] = MAX(dp[i - 2][0] + a[i - 1] + a[i], dp[i - 2][1] + a[i]);
   }
   printf("%d", dp[n][1]);
   return 0;
}