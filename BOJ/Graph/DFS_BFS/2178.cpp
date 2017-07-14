#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 103;
vector<int> a[(MXN * MXN)];
bool chk[(MXN * MXN)]; // is visited ?
int dist[(MXN * MXN)];
queue<int> q;

int main()
{
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i = 0; i < n; i++)
   {
      for(int j = 1; j <= m; j++)
      {
         int t, idx;
         scanf("%1d", &t);
         idx = (i*m) + j;
         chk[idx] = dist[idx] = (t != 1);
         if(!chk[idx])
         {
            if((j - 1) % m != 0 && !chk[idx - 1])
            {
               a[idx].push_back(idx - 1);
               a[idx - 1].push_back(idx);
            }
            if(i > 0 && !chk[idx - m])
            {
               a[idx].push_back(idx - m);
               a[idx - m].push_back(idx);
            }
         }
      }
   }
   // BFS
   q.push(1), chk[1] = true;
   while(!q.empty())
   {
      int i = q.front(); q.pop();
      for(auto it : a[i])
      {
         if(!chk[it])
         {
            chk[it] = true;
            q.push(it);
            dist[it] += dist[i] + 1;
         }
      }
   }
   printf("%d", dist[(n*m)] + 1);
   return 0;
}
