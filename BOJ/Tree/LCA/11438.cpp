#include <cstdio>
#include <queue>
using namespace std;

const int ndiv = 18, MXN = 100001;
int p[MXN][ndiv+1], depth[MXN];
queue <pair<int, int>> q;  // edge info

int main()
{
   int n, a, b;
   scanf("%d", &n);
   p[1][0] = 1, depth[1] = 1;
   for(int i = 1; i < n; i++)
   {
      scanf("%d %d", &a, &b);
      if(a == 1) p[b][0] = 1, depth[b] = 2;
      else if(b == 1) p[a][0] = 1, depth[a] = 2;
      else q.push({a, b});
   }
   while(!q.empty())
   {
      pair<int, int> e = q.front(); q.pop();
      int a = e.first, b = e.second;
      if(p[a][0] && !p[b][0])
         p[b][0] = a, depth[b] = depth[a] + 1;
      else if(!p[a][0] && p[b][0])
         p[a][0] = b, depth[a] = depth[b] + 1;
      else if(!p[a][0] && !p[b][0])
         q.push(e);
   }
   // p[i][j] = parent node (depth diff = 2^j)
   for(int j = 0; j <= ndiv; j++)
      for(int i = 2; i <= n; i++)
         if(p[i][j])
            p[i][j + 1] = p[ p[i][j] ][j];

   int m;
   scanf("%d", &m);
   while(m--)
   {
      scanf("%d %d", &a, &b);
      int v1 = a, v2 = b, diff = 0;
      if(depth[a] > depth[b])
         v1 = a, v2 = b, diff = depth[a] - depth[b];
      else if(depth[a] < depth[b])
         v1 = b, v2 = a, diff = depth[b] - depth[a];

      // v1 is going to the same depth of v2
      for(int i = 0; diff > 0; i++, diff /= 2)
         if(diff % 2)
            v1 = p[v1][i];

      // v1 & v2 are on the same depth, but value is different
      if(v1 != v2)
      {
         for(int j = ndiv - 1; j >= 0; j--)
         {
            if(p[v1][j] && p[v1][j] != p[v2][j])
            {
               v1 = p[v1][j];
               v2 = p[v2][j];
            }
         }
         v1 = p[v1][0];
      }
      printf("%d\n", v1);
   }
   return 0;
}