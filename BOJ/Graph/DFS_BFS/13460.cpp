#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MXN    10
char a[MXN + 2][MXN + 2];
int n, m, dist[(MXN*MXN) + 1], go[(MXN*MXN) + 1];
vector<int> adj[(MXN*MXN) + 1];

void bfs(int s)
{
   queue<int> q;
   q.push(s), dist[s] = 0;
   while(!q.empty())
   {
      int i = q.front(); q.pop();
      for(auto it : adj[i])
      {
         if(dist[it] == -1)
         {
            q.push(it);
            dist[it] = dist[i] + 1;
            go[it] = i;
         }
      }
   }
}

int main()
{
   int b, r, o;
   scanf("%d %d", &n, &m);
   for(int i = 1; i <= n; i++)
   {
      getchar();
      for(int j = 1; j <= m; j++)
      {
         scanf("%c", &a[i][j]);
         if(a[i][j] == '#')
            continue;
         int tmp = ((i - 1)*m) + j;
         if(a[i][j] == 'B')
            b = tmp;
         else if(a[i][j] == 'R')
            r = tmp;
         else if(a[i][j] == 'O')
            o = tmp;

         if(a[i - 1][j] != '#')
            adj[tmp].push_back(tmp - m), adj[tmp - m].push_back(tmp);
         if(a[i][j - 1] != '#')
            adj[tmp].push_back(tmp - 1), adj[tmp - 1].push_back(tmp);

         dist[i*j] = -1;
      }
   }
   bfs(o);
   // for(int i = 1; i <= (n*m); i++)
   //    printf("%d : %d\n", i, dist[i]);
   int ans = -1;

   printf("%d %d %d", o, r, b);
   return 0;
}