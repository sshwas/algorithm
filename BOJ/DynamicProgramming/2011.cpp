#include <cstdio>

const int mod = 1000000;
int dp[5001];
char s[5001];
int main()
{
   int i = 1;
   scanf("%s", &s);
   dp[0] = (s[0] != '0');
   while(s[i] != '\0')
   {
      if(s[i] >= '1' && s[i] <= '9')
         dp[i] += dp[i - 1];
      int t = (s[i - 1] - '0') * 10 + (s[i] - '0');
      if(t >= 10 && t <= 26)
         dp[i] += (i<2 ? 1 : dp[i - 2]);
      dp[i] %= mod;
      i++;
   }
   printf("%d", dp[i - 1]);
   return 0;
}