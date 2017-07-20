#include <cstdio>
#define MAX(a,b)  ((a)>(b) ? (a):(b))
#define MXN    11

char a[MXN + 1][MXN + 1];
int cost[6][6] = {{100, 70, 40}, {70, 50, 30}, {40, 30, 20}}, n, dp[MXN + 1][MXN + 1];
bool chk[MXN + 1][MXN + 1];

int f(int x, int y, int sum)
{
   if(y > n)
      return f(x + 1, 1, sum);
   if(x > n)
      return sum;
   /*if(dp[x][y])
      return dp[x][y];*/
   if(chk[x][y])
   {
      dp[x][y] = MAX(dp[x][y], f(x, y + 1, sum));
      return dp[x][y];
   }

   chk[x][y] = true;
   dp[x][y] = MAX(dp[x][y], f(x, y + 1, sum));
   if(y < n && !chk[x][y + 1])
   {
      chk[x][y + 1] = true;
      dp[x][y] = MAX(dp[x][y], f(x, y + 2, sum + (cost[a[x][y] - 'A'][a[x][y + 1] - 'A'])) );
      chk[x][y + 1] = false;
   }
   if(x < n && !chk[x + 1][y])
   {
      chk[x + 1][y] = true;
      dp[x][y] = MAX(dp[x][y], f(x, y + 1, sum + (cost[a[x][y] - 'A'][a[x + 1][y] - 'A'])) );
      chk[x + 1][y] = false;
   }
   chk[x][y] = false;
   return dp[x][y];
}

int main()
{
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
   {
      getchar();
      for(int j = 1; j <= n; j++)
         scanf("%c", &a[i][j]);
   }

   printf("%d", f(1, 1, 0));
   return 0;
}