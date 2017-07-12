// Kruskal algorithm
#include <cstdio>

typedef struct edge
{
   int a, b, w;
} EDGE;

const int MXN = 100000, MXM = 1000000;
EDGE e[MXM + 1], tmp[MXM + 1];
int rep[MXN + 1]; // parent vertex info

int f(int x)   // return representative vertex's index
{
   if(x == rep[x])
      return x;
   else
      return (rep[x] = f(rep[x]));
}
void mergesort(int l, int r)
{
   if(l < r)
   {
      int m = (l + r) / 2;
      mergesort(l, m);
      mergesort(m + 1, r);
      // p1 [l ~ m], p2 [m+1 ~ r], p3 [l ~ r]
      int p1 = l, p2 = m + 1, p3 = l;
      while(p1 <= m && p2 <= r)
      {
         if(e[p1].w < e[p2].w) // judgement factor is weight(cost)
            tmp[p3++] = e[p1++];
         else
            tmp[p3++] = e[p2++];
      }
      while(p1 <= m) tmp[p3++] = e[p1++];
      while(p2 <= r) tmp[p3++] = e[p2++];
      for(int i = l; i <= r; i++)
         e[i] = tmp[i];
   }
}

int main()
{
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i = 0; i < m; i++)
      scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].w);
   for(int i = 0; i <= n; i++)
      rep[i] = i;

   mergesort(0, m-1);

   // scan the all of original edge data,
   // BUT if the # of edges will be ( n-2 ), that's the 2 Minimum Spanning Trees.
   int cnt = 0;
   long long ans = 0;
   for(int i = 0; i < m; i++)
   {
      int r1 = f(e[i].a), r2 = f(e[i].b);
      if(r1 == r2)   // a and b are in the same union
         continue;

      rep[r2] = r1;
      ans += e[i].w;
      cnt++;
      if(cnt == n - 2)
         break;
   }
   printf("%lld", ans);
   return 0;
}