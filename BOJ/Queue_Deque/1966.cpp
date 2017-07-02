#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXNUM 101

int original[MAXNUM], sorted[MAXNUM];

int main()
{
   int t, N, M, i, cnt, ptr;
   scanf("%d", &t);
   while(t--)
   {
      scanf("%d %d", &N, &M);
      for(i = 0; i < N; i++)
      {
         scanf("%d", &original[i]);
         sorted[i] = original[i];
      }
      sort(sorted, sorted + N);

      i = N-1;
      ptr = cnt = 0;
      while(sorted[i] >= original[M])     // original[M] means Target Priority
      {
         if(sorted[i] == original[ptr])
         {
            if(M == ptr)
               break;
            original[ptr] = 0;
            cnt++; i--;
         }
         ptr++;
         ptr = ptr % N;
      }
      printf("%d\n", cnt+1);
   }
}