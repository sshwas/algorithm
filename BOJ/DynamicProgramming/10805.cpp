#include <cstdio>

#define MAXVALUE    0x7fffffff
#define MAX(a,b)    (a>b?a:b)
#define MIN(a,b)    (a<b?a:b)

int dp[51][51][51][51];
int main()
{
   int h1, w1, h2, w2, i, j, k, m, n, min;
   scanf("%d %d %d %d", &h1, &w1, &h2, &w2);

   // calculation for square, rectangle
   // refer to problem no.10803
   for(i = 1; i <= h1; i++)
   {
      for(j = 1; j <= w1; j++)
      {
         if(i == j)
         {
            dp[i][j][0][0] = 1;
            continue;
         }
         if(i == 1 || j == 1)
         {
            dp[i][j][0][0] = MAX(i, j);
            continue;
         }
         if(i%j == 0)
         {
            dp[i][j][0][0] = i / j;
            continue;
         }

         min = MAXVALUE;
         if(i >= 3 * j)
            min = MIN(min, dp[i - j][j][0][0] + 1);
         else
         {
            for(k = 1; k <= i / 2; k++)
               min = MIN(min, dp[k][j][0][0] + dp[i - k][j][0][0]);
            for(k = 1; k <= j / 2; k++)
               min = MIN(min, dp[i][k][0][0] + dp[i][j - k][0][0]);
         }
         dp[j][i][0][0] = dp[i][j][0][0] = min;
      }
   }

   // calculation for 'L' shape
   for(i = 2; i <= h1; i++)
   {
      for(j = 2; j <= w1; j++)
      {
         for(m = 1; m < i; m++)
         {
            for(n = 1; n < j; n++)
            {
               if(dp[i][j][m][n])
                  continue;

               min = MIN(dp[m][j - n][0][0] + dp[i - m][j][0][0], dp[i][j - n][0][0] + dp[i - m][n][0][0]);
               if(i == m + 1 && j == n + 1)
               {
                  dp[j][i][n][m] = dp[i][j][m][n] = min;
                  continue;
               }

               for(k = m+1; k < i; k++)
                  min = MIN(min, dp[k][j][m][n] + dp[i - k][j][0][0]);
               for(k = n+1; k < j; k++)
                  min = MIN(min, dp[i][k][m][n] + dp[i][j - k][0][0]);
               for(k = 1; k < m; k++)
                  min = MIN(min, dp[i-k][j][m-k][n] + dp[k][j-n][0][0]);
               for(k = 1; k < n; k++)
                  min = MIN(min, dp[i][j-k][m][n-k] + dp[i-m][k][0][0]);
               dp[j][i][n][m] = dp[i][j][m][n] = min;
            }
         }
      }
   }

   printf("%d\n", dp[h1][w1][h2][w2]);
   return 0;
}