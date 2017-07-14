#include <cstdio>
#include <queue>
using namespace std;

pair<int, int> p[50001];   // first = parent node, second = depth
queue <pair<int, int>> q;  // edge info
int f(int x, int y)
{
   if(x == 1 || y == 1) return 1;
   if(x == y) return x;
   if(p[x].second == p[y].second) return f(p[x].first, p[y].first);
   if(p[x].second > p[y].second) return f(p[x].first, y);
   else return f(x, p[y].first); // (p[x].second < p[y].second)
}
int main()
{
   int n, a, b;
   scanf("%d", &n);
   p[1] = {1, 1};
   for(int i = 1; i < n;i++)
   {
      scanf("%d %d", &a, &b);
      if(a == 1) p[b] = {1, p[1].second + 1};
      else if(b == 1) p[a] = {1, p[1].second + 1};
      else q.push({a, b});
   }
   while(!q.empty())
   {
      pair<int, int> e = q.front(); q.pop();
      int a = e.first, b = e.second;
      if(p[a].first && !p[b].first)
         p[b] = {a, p[a].second + 1};
      else if(!p[a].first && p[b].first)
         p[a] = {b, p[b].second + 1};
      else if(!p[a].first && !p[b].first)
         q.push(e);
   }
   int m;
   scanf("%d", &m);
   while(m--)
   {
      scanf("%d %d", &a, &b);
      printf("%d\n", f(a, b));
   }
   return 0;
}