#include <stdio.h>

int a[101];
char dp[101][1001];

int main()
{
   int N, S, M, i, j, ans = -1;
   scanf("%d %d %d", &N, &S, &M);

   for(i = 1; i <= N; i++)
      scanf("%d", &a[i]);

   // assign digit 1 for the all of possible cases 
   dp[0][S] = 1;
   for(i = 1; i <= N; i++)
   {
      for(j = 0; j <= M; j++)
      {
         if(dp[i - 1][j])
         {
            if(j - a[i] >= 0)
               dp[i][j - a[i]] = 1;
            if(j + a[i] <= M)
               dp[i][j + a[i]] = 1;
         }
      }
   }
   for(i = 0; i <= M; i++)
      if(dp[N][i])
         ans = i;

   printf("%d", ans);
   return 0;
}