#include <cstdio>

char Q[14];
int N, cnt;

void nqueens(int n)
{
   int i, j;
   char chk;
   for(i = 1; i <= N; i++)
   {
      chk = 0;
      for(j = n - 1; j >= 1; j--)
      {
         if((i == Q[j]) || (i == Q[j] + n - j) || (i == Q[j] + j - n))
         {
            chk = 1;
            break;
         }
      }
      if(!chk)
      {
         Q[n] = i;
         if(n == N)
         {
            cnt++;
            return;
         }
         else
         {
            nqueens(n + 1);
         }
         Q[n] = 0;
      }
   }
}

int main()
{
   scanf("%d", &N);
   cnt = 0;
   nqueens(1);
   printf("%d", cnt);
}
