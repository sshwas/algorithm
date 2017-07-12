// Floyd-Warshall algorithm
#include <cstdio>
#include <algorithm>
using namespace std;

#define MIN(a,b)  ((a)<(b)? (a):(b))
#define INF       ( 1000000000 )

int dist[101][101], maxi[101], rep[100], gn, flag[101];

int main()
{
   int N, M, i, j ,k;
   scanf("%d %d", &N, &M);
   
   // initialization
   for(i = 1; i <= N; i++)
      for(j = 1; j <= N; j++)
         dist[i][j] = (i == j ? 0 : INF);

   while(M--)
   {
      scanf("%d %d", &i, &j);
      dist[i][j] = dist[j][i] = 1;
   }

   // shortest distance ( Floyd-Warshall algorithm )
   for(k = 1; k <= N; k++)
      for(i = 1; i <= N; i++)
         for(j = 1; j <= N; j++)
            dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);
   
   for(i = 1; i <= N; i++)
      for(j = 1; j <= N; j++)
         if(dist[i][j] < INF && dist[i][j] > maxi[i])
            maxi[i] = dist[i][j];

   for(i = 1; i <= N; i++)
   {
      if(!flag[i])
      {
         int t = i;
         for(int j = i; j <= N; j++)
         {
            if(dist[i][j] < INF)
            {
               flag[j] = 1;
               if(maxi[t] > maxi[j])
                  t = j;
            }
         }
         rep[gn++] = t;
      }
   }
   sort(rep, rep + gn);
   printf("%d", gn);
   for(int i = 0; i < gn; i++)
      printf("\n%d", rep[i]);

   return 0;
}