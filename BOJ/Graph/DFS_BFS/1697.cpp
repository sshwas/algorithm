#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 100001, inf = 2e9;
vector<int> a[MXN*2];
bool chk[MXN*2]; // is in Queue ?
int dist[MXN*2];
queue<int> q;

int main()
{
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i = 0; i <= min(n+k, MXN); i++)
   {
      a[i].push_back(i - 1);
      a[i].push_back(i + 1);
      a[i].push_back(i * 2);
   }

   for(int i = 0; i <= min(n+k, MXN); i++)
      dist[i] = inf, chk[i] = false;

   // BFS
   q.push(n), chk[n] = true;
   dist[n] = 0;
   while(!q.empty())
   {
      int i = q.front(); q.pop();
      chk[i] = false;
      for(auto it : a[i])
      {
         if(dist[it] > dist[i] + 1)
         {
            dist[it] = dist[i] + 1;
            if(!chk[it])
            {
               chk[it] = true;
               q.push(it);
            }
         }
      }
   }
   printf("%d", dist[k]);
   return 0;
}
