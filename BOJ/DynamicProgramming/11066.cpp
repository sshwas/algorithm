#include <cstdio>

#define MIN(a,b)  ((a)<(b)? (a):(b))

int dp[501][501],a[501],s[501];

int solve(int i, int j)
{
   int k, min, tmp;
   if(dp[i][j])
      return dp[i][j];
   if(i == j)
      return 0;
   if(j - i == 1)
   {
      dp[i][j] = a[i] + a[j];
      return dp[i][j];
   }

   min = dp[i][i] + solve(i + 1, j);
   for(k = i + 1; k < j; k++)
   {
      tmp = solve(i, k) + solve(k + 1, j);
      min = MIN(min, tmp);
   }
   dp[i][j] = min + s[j] - s[i-1];
   return dp[i][j];
}

int main()
{
   int t, k, i, j;
   scanf("%d", &t);
   while(t--)
   {
      scanf("%d", &k);
      for(i = 1; i <= k; i++)
      {
         scanf("%d", &a[i]);
         s[i] = s[i - 1] + a[i];
         for(j = 1; j <= k; j++)
         {
            dp[i][j] = 0;
         }
      }
      printf("%d\n", solve(1,k));
   }
}