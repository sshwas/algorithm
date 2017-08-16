#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> a[16];
int n, d[16];
int f(int x)
{
   if(x > n + 1)
      return -987654321;
   if(x > n)
      return 0;
   if(d[x])
      return d[x];
   int &ans = d[x];
   ans = max(a[x].second + f(x + a[x].first), f(x + 1));
   return ans;
}

int main()
{
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
      scanf("%d %d", &a[i].first, &a[i].second);

   printf("%d", f(1));
   return 0;
}