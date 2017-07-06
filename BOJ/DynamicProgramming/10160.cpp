#include <cstdio>

const int MOD = 1000000009;
long long d[1000010];
int main()
{
   int i, N, K;
   scanf("%d %d", &N, &K);
   d[6] = 1;
   for(i = 7; i<N+7; i++)
      d[i] = (( long long ) (d[i-1] * K) - (2 * d[i-5]) + d[i-7] + (MOD*2)) % MOD;
   printf("%lld", d[i-1]);
}
