#include <cstdio>
#include <vector>
using namespace std;
#define MAX(a,b)  ((a)>(b) ? (a):(b))

typedef struct block
{
   int e, h, w, idx;
} BLOCK;

BLOCK a[101];
int dp[101], p[101];

void swap(BLOCK *x, BLOCK *y)
{
   BLOCK t = *x;
   *x = *y;
   *y = t;
}
int main()
{
   int n;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
      scanf("%d %d %d", &a[i].e, &a[i].h, &a[i].w), a[i].idx = i;

   for(int i = 1; i < n; i++)
      for(int j = 1; j <= n - i; j++)
         if(a[j].e < a[j + 1].e)
            swap(&a[j], &a[j + 1]);

   for(int i = n; i >= 0; i--)
   {
      dp[i] = a[i].h;
      for(int j = i + 1; j <= n; j++)
      {
         if(i == 0 || a[i].e > a[j].e && a[i].w > a[j].w)
         {
            if(dp[i] < dp[j] + a[i].h)
            {
               dp[i] = dp[j] + a[i].h;
               p[i] = j;
            }
         }
      }
   }
   vector<int> ans;
   int cur = 0;
   while(p[cur] != 0)
   {
      ans.push_back(a[p[cur]].idx);
      cur = p[cur];
   }
   printf("%d\n", ans.size());
   for(int i = ans.size() - 1; i >= 0; i--)
      printf("%d\n",ans[i]);

   return 0;
}