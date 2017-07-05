#include<cstdio>
#include<cstring>

#define mod 5000000

int n, k, bit[100001], a[100000], dp[100000];
int main()
{
   scanf("%d %d", &n, &k);
   for(int i = 0; i < n; i++)
      scanf("%d", &a[i]), dp[i] = 1;

   for(int i = 2; i <= k; i++)
   {
      memset(bit, 0, sizeof(bit));
      for(int j = 0; j < n; j++)
      {
         for(int h = a[j]; h <= 1e5; h += h&-h) 
            bit[h] = (bit[h] + dp[j]) % mod;
         dp[j] = 0;
         for(int h = a[j] - 1; h; h -= h&-h) 
            dp[j] = (dp[j] + bit[h]) % mod;
      }
   }
   int s = 0;
   for(int i = 0; i < n; i++)
      s = (s + dp[i]) % mod;
   printf("%d", s);
   return 0;
}