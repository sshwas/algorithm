#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MXV = 20005, inf = 2e9;
vector<pair<int, int>> ed[MXV];
int dist[MXV];
queue<int> q;
bool inQ[MXV];
int main()
{
   int nv, ne;
   scanf("%d %d", &nv, &ne);
   for(int i = 1; i <= ne; i++)
   {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      ed[u].push_back({v, w});
   }
   for(int i = 1; i <= nv; i++)
      dist[i] = inf, inQ[i] = false;
   
   int s, e;
   scanf("%d %d", &s, &e);
   dist[s] = 0;
   q.push(s), inQ[s] = true;
   while(!q.empty())
   {
      int a = q.front(); q.pop();
      inQ[a] = false;
      for(auto it : ed[a])
      {
         if(dist[it.first] > (dist[a] + it.second))
         {
            dist[it.first] = dist[a] + it.second;
            if(!inQ[it.first])
            {
               q.push(it.first);
               inQ[it.first] = true;
            }
         }
      }
   }
   printf("%d", dist[e]);
   return 0;
}