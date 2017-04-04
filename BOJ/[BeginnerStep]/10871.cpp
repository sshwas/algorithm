#include <cstdio>

int main()
{
   int N, X, tmp;
   scanf("%d %d", &N, &X);

   while(N--)
   {
      scanf("%d", &tmp);
      if(tmp < X)
         printf("%d ", tmp);
   }
}