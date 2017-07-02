#include <stdio.h>

#define MAX(a,b)  ((a)>(b)? (a):(b))

int dp[1001][31], a[1001], t, w;

int solve(int sec, int tree)
{
   int tmp;
   if(sec == t + 1 && tree <= w)
      return 0;
   if(tree > w)
      return 0;
   if(dp[sec][tree])
      return dp[sec][tree];
   tmp = tree % 2 + 1;
   dp[sec][tree] = MAX(solve(sec + 1, tree), solve(sec + 1, tree + 1)) + (tmp == a[sec] ? 1 : 0);
   return dp[sec][tree];
}

int main()
{
   int i, j;
   scanf("%d %d", &t, &w);
   for(i = 1; i <= t; i++)
      scanf("%d", &a[i]);

   printf("%d", MAX(solve(1, 0), solve(1, 1)));
   return 0;
}