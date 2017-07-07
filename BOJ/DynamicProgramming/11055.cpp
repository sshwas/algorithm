// Largest Increasing Subsequence
#include <cstdio>

#define MAX(a,b)  ((a)>(b) ? (a):(b))
int dp[1001], a[1001];
int main()
{
   int n;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
   {
      scanf("%d", &a[i]);
      dp[i] = a[i];
      for(int j = 1; j < i; j++)
         dp[i] = MAX(dp[i], (a[j] < a[i] ? (dp[j] + a[i]) : a[i]));
   }
   int lis = 0;
   for(int j = 1; j <= n; j++)
      lis = MAX(lis, dp[j]);
   printf("%d", lis);
   return 0;
}