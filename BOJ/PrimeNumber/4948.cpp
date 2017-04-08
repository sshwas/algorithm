// Chebyshev's Theorem 

#include <cstdio>

int isPrime(int number)
{
   int i;
   if(number % 2 == 0)
      return (number == 2);
   if(number % 3 == 0)
      return (number == 3);
   if(number % 5 == 0)
      return (number == 5);
   else
   {
      for(i = 7; i*i <= number; i += 2)
         if(number%i == 0)
            return 0;

      return (number != 1);
   }
}

int main(void)
{
   int n, i, cnt =0;
   scanf("%d", &n);
   while(n)
   {
      for(i = n+1; i <= (2*n); i++)
         if(isPrime(i))
            cnt++;

      printf("%d\n", cnt);
      cnt = 0;
      scanf("%d", &n);
   }
}