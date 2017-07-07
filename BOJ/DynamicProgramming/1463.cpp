#include <cstdio>

#define MIN(a,b)  ((a)<(b) ? (a):(b))
int dp[1000001];
int main()
{
   int x;
   scanf("%d", &x);
   dp[1] = 0;
   for(int i = 2; i <= x; i++)
   {
      dp[i] = dp[i - 1];
      if(i % 3 == 0)
         dp[i] = MIN(dp[i], dp[i / 3]);
      if(i % 2 == 0)
         dp[i] = MIN(dp[i], dp[i / 2]);
      dp[i]++;
   }
   printf("%d", dp[x]);
   return 0;
}