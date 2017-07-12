// Kruskal algorithm
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

typedef struct star
{
   double x, y;
} STAR;
typedef struct edge
{
   int a, b;
   double w;
} EDGE;

const int MXN = 100, MXM = 10000;
EDGE e[MXM + 1], tmp[MXM + 1];
int rep[MXN + 1]; // parent vertex info
STAR st[101];
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
   int n;
   scanf("%d", &n);
   for(int i = 0; i < n; i++)
      scanf("%lf %lf", &st[i].x, &st[i].y);

   int ne = 0; // number of edges
   for(int i = 0; i < n; i++)
   {
      for(int j = i + 1; j < n; j++)
      {
         e[ne].a = i;
         e[ne].b = j;
         e[ne].w = sqrt(pow(abs(st[i].x - st[j].x), 2) + pow(abs(st[i].y - st[j].y), 2));
         ne++;
      }
   }

   for(int i = 0; i <= ne; i++)
      rep[i] = i;

   mergesort(0, ne - 1);

   // scan the all of original edge data,
   // BUT if the # of edges will be ( n-1 ), that's the Minimum Spanning Tree
   //                                        because all the vertices are connected.
   int cnt = 0;
   double ans = 0;
   for(int i = 0; i < ne; i++)
   {
      int r1 = f(e[i].a), r2 = f(e[i].b);
      if(r1 == r2)   // a and b are in the same union
         continue;

      rep[r2] = r1;
      ans += e[i].w;
      cnt++;
      if(cnt == n - 1)
         break;
   }
   printf("%.2lf", ans);
   return 0;
}