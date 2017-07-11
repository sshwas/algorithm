#include <cstdio>

int a[101], dp[101][101];
bool c[101][101];
int min = -32768 * 101;

int go(int n, int m)
{
   if(m == 0)
      return 0;
   if(n <= 0)
      return min;
   if(c[n][m])
      return dp[n][m];

   c[n][m] = true;
   dp[n][m] = go(n - 1, m);
   int sum = 0;
   for(int k = n; k >= 1; k--)
   {
      sum += a[k];
      int temp = go(k - 2, m - 1) + sum;
      if(dp[n][m] < temp)
         dp[n][m] = temp;
   }
   return dp[n][m];
}

int main()
{
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
   
   printf("%d\n", go(n, m));
   return 0;
}