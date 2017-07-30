#include <cstdio>
#define MXN    ( 257 )
#define abs(a,b)  ((a)>(b) ? (a-b):(b-a))
#define min(a,b)  ((a)>(b) ? (b):(a))

int d[MXN][MXN], w[MXN][MXN], a[MXN], n;
int f(int x, int y)
{
   if(x == y)
      return 0;
   if(x + 1 == y)
      return (abs(a[x], a[y]));
   if(d[x][y])
      return d[x][y];
   int &ans = d[x][y];
   ans = abs(a[x], w[x + 1][y]) + f(x + 1, y);
   for(int i = x+1; i < y; i++)
   {
      ans = min(ans, abs(w[x][i], w[i+1][y]) + f(x, i) + f(i+1, y));
   }
   return ans;
}
int main()
{
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
      scanf("%d", &a[i]);

   for(int i = 1; i <= n; i++)
   {
      w[i][i] = a[i];
      for(int j = i + 1; j <= n; j++)
         w[i][j] = min(w[i][j - 1], a[j]);
   }
   printf("%d", f(1, n));
   return 0;
}