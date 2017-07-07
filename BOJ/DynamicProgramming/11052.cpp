#include <cstdio>

#define MAX(a,b)  ((a)>(b) ? (a):(b))
int dp[1001],p[1001];
int main()
{
   int n;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
   {
      scanf("%d", &p[i]);
      dp[i] = p[i];
      for(int j = 1; j < i; j++)
         dp[i] = MAX(dp[i], dp[i-j] + p[j]);
   }
   printf("%d", dp[n]);
   return 0;
}