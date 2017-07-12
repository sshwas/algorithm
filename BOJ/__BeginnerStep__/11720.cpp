#include <cstdio>

int main()
{
   int n,sum=0;
   char str[101];
   scanf("%d\n%s", &n, str);
   while(n--)
   {
      sum += (str[n] - '0');
   }
   printf("%d", sum);
}