#include <stdio.h>

int dp[31], dp2[31];
int main()
{
   int N, i, tmp;
   scanf("%d", &N);

   dp[1] = 1, dp[2] = 3;
   for(i = 3; i <= N; i++)
      dp[i] = dp[i - 2] * 2 + dp[i - 1];

   dp2[1] = 1, dp2[2] = 3;
   for(i = 3; i <= N; i++)
   {
      if(i & 1)
         tmp = dp[(i - 1) / 2];
      else
         tmp = dp[i / 2] + (2 * dp[(i - 2) / 2]);
      dp2[i] = (dp[i] + tmp) / 2;
   }
   printf("%d", dp2[N]);
   return 0;
}