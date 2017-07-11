#include <cstdio>

const long long mod = 100000;
char s[201];
bool over = false;
long long dp[200][200];
char open[5] = "({[";
char close[5] = ")}]";

long long go(int i, int j)
{
   if(i > j)
      return 1;
   if(dp[i][j] != -1)
      return dp[i][j];
   dp[i][j] = 0;
   for(int k = i + 1; k <= j; k += 2)
   {
      for(int l = 0; l<3; l++)
      {
         if(s[i] == open[l] || s[i] == '?')
         {
            if(s[k] == close[l] || s[k] == '?')
            {
               long long temp = go(i + 1, k - 1) * go(k + 1, j);
               if(dp[i][j] + temp > mod)
                  over = true;
               dp[i][j] = (dp[i][j] + temp) % mod;
            }
         }
      }
   }
   return dp[i][j];
}

int main()
{
   int n;
   scanf("%d\n%s", &n, s);
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
         dp[i][j] = -1;

   long long ans = go(0, n - 1);
   if(over)
      printf("%05lld\n", ans);
   else
      printf("%lld\n", ans);
   return 0;
}