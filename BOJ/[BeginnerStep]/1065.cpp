#include <cstdio>

int main()
{
   int N, cnt=0, d, j;

   scanf("%d", &N);
   for(int i = 1; i <= N; i++) {
      d = i / 10 % 10 - i % 10;
      for(j = i/10 ;j > 9; j/=10)
         if(j / 10 % 10 - j % 10 != d)
            break;
      cnt += (j<10);
   }
   printf("%d", cnt);
}