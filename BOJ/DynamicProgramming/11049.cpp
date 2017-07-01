#include <cstdio>

#define MIN(a,b)  ((a)<(b)? (a):(b))

int dp[501][501], a[501][2];

int solve(int i, int j)
{
   int k, min, tmp;
   if(dp[i][j])
      return dp[i][j];
   if(i == j)
      return 0;
   if(j - i == 1)
   {
      dp[i][j] = a[i][0] * a[i][1] * a[j][1];
      return dp[i][j];
   }

   min = (a[i][0] * a[i][1] * a[j][1]) + solve(i + 1, j);
   for(k = i + 1; k < j; k++)
   {
      tmp = solve(i, k) + solve(k + 1, j) + (a[i][0] * a[k][1] * a[j][1]);
      min = MIN(min, tmp);
   }
   dp[i][j] = min;
   return dp[i][j];
}

int main()
{
   int k, i;
   scanf("%d", &k);
   for(i = 1; i <= k; i++)
      scanf("%d %d", &a[i][0], &a[i][1]);
   printf("%d\n", solve(1, k));
}