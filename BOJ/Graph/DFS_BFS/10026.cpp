#include <stdio.h>

#define MAXNUM 100
int a[(MAXNUM * MAXNUM) + 1][4], a_blind[(MAXNUM * MAXNUM) + 1][4], q[(MAXNUM * MAXNUM) + 1], N;
char rgb[(MAXNUM * MAXNUM) + 1];

int BFS(int arr[][4])
{
   int head = 0, tail = 0, group = 0;
   char chk[(MAXNUM * MAXNUM) + 1] = {0, };  // init visit info.
   for(int i = 1; i <= (N*N); i++)
   {
      if(!chk[i])
      {
         q[head++] = i;
         while(head != tail)
         {
            int tmp = q[tail++];
            for(int j = 0; j < 4; j++)
            {
               if(arr[tmp][j] && !chk[arr[tmp][j]])
               {
                  q[head++] = arr[tmp][j];
                  chk[arr[tmp][j]] = 1;
               }
            }
         }
         group++;
      }
   }
   return group;
}
int main()
{
   int i, j, tmp;
   scanf("%d", &N);
   for(i = 0; i < N; i++)
   {
      scanf("\n");
      for(j = 1; j <= N; j++)
      {
         tmp = (i*N) + j;
         scanf("%c", &rgb[tmp]);
         // [x][0] = x's east,[x][1] = x's west,[x][2] = x's south,[x][3] = x's north
         if((j - 1) % N != 0)
         {
            if(rgb[tmp - 1] == rgb[tmp])
            {
               a_blind[tmp][1] = a[tmp][1] = tmp - 1;
               a_blind[tmp - 1][0] = a[tmp - 1][0] = tmp;
            }
            else if((rgb[tmp - 1] == 'R' && rgb[tmp] == 'G') || (rgb[tmp - 1] == 'G' && rgb[tmp] == 'R'))
            {
               a_blind[tmp][1] = tmp - 1;
               a_blind[tmp - 1][0] = tmp;
            }
         }
         if(i > 0)
         {
            if(rgb[tmp - N] == rgb[tmp])
            {
               a_blind[tmp][3] = a[tmp][3] = tmp - N;
               a_blind[tmp - N][2] = a[tmp - N][2] = tmp;
            }
            else if((rgb[tmp - N] == 'R' && rgb[tmp] == 'G') || (rgb[tmp - N] == 'G' && rgb[tmp] == 'R'))
            {
               a_blind[tmp][3] = tmp - N;
               a_blind[tmp - N][2] = tmp;
            }
         }
      }
   }
   printf("%d %d", BFS(a), BFS(a_blind));
   return 0;
}