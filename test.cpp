#include <cstdio>

// Use the sieve of Eratosthenes
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
   int m, n, sum = 0, min, i;
   char chk = 0;
   scanf("%d %d", &m, &n);
   min = n;
   for(i = m; i <= n; i++)
   {
      if(isPrime(i))
      {
         chk = 1;
         sum += i;
         min = (min > i ? i : min);
      }
   }
   if(!chk)
      printf("-1");
   else
   {
      printf("%d\n", sum);
      printf("%d\n", min);
   }
}