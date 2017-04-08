// Goldbach¡¯s Conjecture

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
   int n, m, i, p1, p2;
   int x[10000][2];

   scanf("%d", &n);
   for(i = 0; i < n; i++)
   {
      scanf("%d", &m);

      p1 = p2 = (m / 2);
      if((p1 % 2 == 0) && (p1 != 2))
      {
         p1--;
         p2++;
      }
      while(p1 >= 2)
      {
         if(isPrime(p1) && isPrime(p2))
            break;
         p1 -= 2;
         p2 += 2;
      }
      x[i][0] = p1;
      x[i][1] = p2;
   }

   for(i = 0; i < n; i++)
      printf("%d %d\n", x[i][0], x[i][1]);
}