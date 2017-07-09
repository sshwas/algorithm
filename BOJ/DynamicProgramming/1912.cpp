#include <cstdio>

const int MXN = 100000;
int a[MXN+1], dp[MXN+1];
int main()
{
   int n;
   scanf("%d", &n);
   for (int i = 1; i <= n; i++)
   {
      scanf("%d", &a[i]);
      if(a[i] <= dp[i - 1] + a[i])
         dp[i] = dp[i - 1] + a[i];
      else
         dp[i] = a[i];
   }
   int max = -1001;
   for (int i = 1; i <= n; i++)
      max = (max < dp[i] ? dp[i] : max);

   printf("%d", max);
   return 0;
}