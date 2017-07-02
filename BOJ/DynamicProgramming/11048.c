#include <stdio.h>

#define MAX(a,b)  ((a)>(b)? (a):(b))

int dp[1001][1001], a[1001][1001];
int main()
{
   int N, M, i,j;
   scanf("%d %d", &N, &M);
   for(i = 1; i <= N; i++)
      for(j = 1; j <= M; j++)
         scanf("%d", &a[i][j]);

   for(i = 1; i <= N; i++)
      for(j = 1; j <= M; j++)
         dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
   printf("%d", dp[N][M]);
   return 0;
}