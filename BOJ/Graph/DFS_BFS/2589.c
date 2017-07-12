#include <stdio.h>

#define MAXNUM 50
int a[(MAXNUM * MAXNUM) + 1][4], q[(MAXNUM * MAXNUM) + 1];
char chk[(MAXNUM * MAXNUM) + 1], dist[(MAXNUM * MAXNUM) + 1];

int main()
{
   int N, M, head=0, tail=0, i, j, tmp, max = 0;
   char c;
   scanf("%d %d", &N, &M);
   for(i = 0; i < N; i++)
   {
      scanf("\n");
      for(j = 1; j <= M; j++)
      {
         scanf("%c", &c);
         tmp = (i*M) + j;
         chk[tmp] = dist[tmp] = (c != 'L');
         if(!chk[tmp])
         {
            // [x][0] = x's east,[x][1] = x's west,[x][2] = x's south,[x][3] = x's north
            if((j - 1) % M != 0 && !chk[tmp - 1])
            {
               a[tmp][1] = tmp - 1;
               a[tmp - 1][0] = tmp;
            }
            if(i > 0 && !chk[tmp - M])
            {
               a[tmp][3] = tmp - M;
               a[tmp - M][2] = tmp;
            }
         }
      }
   }

   for(i = 1; i <= (N*M); i++)
   {
      if(!dist[i])
      {
         //BFS
         q[head++] = i;
         dist[i] = 1;
         while(head != tail)
         {
            tmp = q[tail++];
            for(j = 0; j < 4; j++)
            {
               if(a[tmp][j] && !dist[a[tmp][j]])
               {
                  q[head++] = a[tmp][j];
                  dist[a[tmp][j]] = dist[tmp] + 1;
               }
            }
         }
      }
      if(max < dist[tmp])
         max = dist[tmp] - 1;
      head = tail = 0; // avoid runtime error

      for(j = 1; j <= (N*M); j++)
         dist[j] = chk[j];
   } 
   printf("%d", max);
   return 0;
}