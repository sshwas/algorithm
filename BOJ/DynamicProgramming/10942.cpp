#include <cstdio>

int a[2001];
char dp[2001][2001];
int main()
{
   int n, m, i;
   scanf("%d", &n);
   for(i = 1; i <= n; i++)
   {
      scanf("%d", &a[i]);
      dp[i][i] = 1;
   }
   for(i = 1; i < n; i++)
      dp[i][i + 1] = (a[i] == a[i + 1]);
   for(int k = 3; k <= n; k++)
   {
      for(i = 1; i <= n - k + 1; i++)
      {
         int j = i + k - 1;
         dp[i][j] = (a[i] == a[j] && dp[i + 1][j - 1]);
      }
   }
   scanf("%d", &m);
   while(m--)
   {
      int s, e;
      scanf("%d %d", &s, &e);
      printf("%d\n", dp[s][e]);
   }
   return 0;
}