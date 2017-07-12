#include <cstdio>
#include <algorithm>
using namespace std;

const int MXN = 10000;
int a[MXN + 1], t[MXN + 1], p[MXN + 1];

int f(int x)
{
   if(x == p[x]) return x;
   else return (p[x] = f(p[x]));
}
int main()
{
   int n;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
   {
      scanf("%d", &a[i]);
      t[i] = a[i];
      p[i] = i;
   }
   sort(t + 1, t + n + 1);
   
   int nv = n;
   for(int i = 1; i <= n; i++)
      if(a[i] == t[i])
         nv--;

   long long ans = 0;
   int ne = 0;
   for(int i = 1; i <= n; i++)
   {
      if(ne >= nv - 1)
         break;
      for(int j = 1; j <= n; j++)
      {
         if(a[i] == t[i] || a[j] == t[j] || i == j)
            continue;
         int p1 = f(i), p2 = f(j);
         if(p1 == p2)
            continue;
         p[p1] = p2;
         ans += (t[i] + t[j]);
 //  printf("%d:%d:%d:%d\n", i,j,t[i],t[j]);
         ne++;
      }
   }
   printf("%d", ans);
   return 0;
}