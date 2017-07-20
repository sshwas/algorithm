#include <cstdio>
#define RoundupMultiple(a, x)    ((a+(x-1))/x)

int a[1000001];
int main()
{
   int n, b, c;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
   scanf("%d %d", &b, &c);

   long long sum = 0;
   for(int i = 1; i <= n; i++)
   {
      a[i] -= b, sum++;
      if(a[i] > 0)
         sum += RoundupMultiple(a[i], c);
   }
   printf("%lld", sum);
   return 0;
}