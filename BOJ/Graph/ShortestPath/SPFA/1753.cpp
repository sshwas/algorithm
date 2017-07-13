#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MXV = 20005, inf = 1000000000;
vector<pair<int, int>> ed[MXV];
int dist[MXV], q[300000], h, t;
bool inQ[MXV];
int main()
{
   int nv, ne, s;
   scanf("%d %d %d", &nv, &ne, &s);
   for (int i = 1; i <= ne; i++)
   {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      ed[u].push_back({ v, w });
   }
   for (int i = 1; i <= nv; i++)
      dist[i] = inf, inQ[i] = false;

   // BFS
   dist[s] = 0;
   q[t++] = s, inQ[s] = true;
   while (h != t)
   {
      int a = q[h++];
      inQ[a] = false;
      for (auto it : ed[a])
      {
         if (dist[it.first] > (dist[a] + it.second))
         {
            dist[it.first] = dist[a] + it.second;
            if (!inQ[it.first])
            {
               q[t++] = it.first;
               inQ[it.first] = true;
            }
         }
      }
   }
   for (int i = 1; i <= nv; i++)
      if (dist[i] >= inf)
         puts("INF");
      else
         printf("%d\n", dist[i]);

   return 0;
}