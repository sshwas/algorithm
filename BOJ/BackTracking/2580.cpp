#include <stdio.h>

#define MAX     0x1FF

int sudo[10][10];
char done = 0;
int rowbit[10] = {0, };
int colbit[10] = {0, };
int squarebit[4][4] = {0, };
int rowzerocnt[10] = {0, };
int colzerocnt[10] = {0, };

int rowcheck(int row)
{
   int i, bitsum = 0;
   for(i = 1; i <= 9; i++)
   {
      bitsum |= (1 << (sudo[row][i] - 1));
   }
   return (bitsum == MAX);
}
int colcheck(int col)
{
   int i, bitsum = 0;
   for(i = 1; i <= 9; i++)
   {
      bitsum |= (1 << (sudo[i][col] - 1));
   }
   return (bitsum == MAX);
}
int squarecheck(int m, int n)
{
   int i, j, bitsum = 0;
   for(i = m - 2; i <= m; i++)
   {
      for(j = n - 2; j <= n; j++)
      {
         bitsum |= (1 << (sudo[i][j] - 1));
      }
   }
   return (bitsum == MAX);
}

void printSudo()
{
   int i, j;
   for(i = 1; i <= 9; i++)
   {
      for(j = 1; j <= 9; j++)
      {
         printf("%d ", sudo[i][j]);
      }
      printf("\n");
   }
   done = 1;
}

void greedyAns()
{
   int i, j, cnt = 0, index, digit;
   // find rows including only 1 zero.
   for(i = 1; i <= 9; i++)
   {
      for(j = 1; j <= 9; j++)
      {
         if(((rowbit[i] >> (j - 1)) & 1) == 0)
            digit = j;
         if(sudo[i][j] == 0)
         {
            cnt++;
            index = j;
         }
      }
      if(cnt == 1)
      {
         sudo[i][index] = digit;
         rowbit[i] |= (1 << (digit - 1));
         colbit[index] |= (1 << (digit - 1));
         squarebit[((i + 2) / 3)][((index + 2) / 3)] |= (1 << (digit - 1));
      }
      cnt = 0;
   }
   // find cols including only 1 zero.
   for(i = 1; i <= 9; i++)
   {
      for(j = 1; j <= 9; j++)
      {
         if(((colbit[i] >> (j - 1)) & 1) == 0)
            digit = j;
         if(sudo[j][i] == 0)
         {
            cnt++;
            index = j;
         }
      }
      if(cnt == 1)
      {
         sudo[index][i] = digit;
         rowbit[index] |= (1 << (digit - 1));
         colbit[i] |= (1 << (digit - 1));
         squarebit[((index + 2) / 3)][((i + 2) / 3)] |= (1 << (digit - 1));
      }
      cnt = 0;
   }
}

void find(int m, int n)
{
   int i;
   if(done)
      return;
   if((m > 1) && (n == 1) && !rowcheck(m - 1))
      return;
   if((m == 9) && (n > 1) && !colcheck(n - 1))
      return;
   if(m >= 10)
   {
      printSudo();
      return;
   }
   if(sudo[m][n] == 0)
   {
      for(i = 1; i <= 9; i++)
      {
         if(((1 << (i - 1)) & rowbit[m]) != 0)
            continue;
         if(((1 << (i - 1)) & colbit[n]) != 0)
            continue;
         if(((1 << (i - 1)) & squarebit[((m + 2) / 3)][((n + 2) / 3)]) != 0)
            continue;

         sudo[m][n] = i;
         rowbit[m] |= (1 << (i - 1));
         colbit[n] |= (1 << (i - 1));
         squarebit[((m + 2) / 3)][((n + 2) / 3)] |= (1 << (i - 1));
         if((m % 3 == 0) && (n % 3 == 0) && !squarecheck(m, n))
         {
            sudo[m][n] = 0;
            rowbit[m] &= ~(1 << (i - 1));
            colbit[n] &= ~(1 << (i - 1));
            squarebit[((m + 2) / 3)][((n + 2) / 3)] &= ~(1 << (i - 1));
            continue;
         }
         if(n == 9)
            find(m + 1, 1);
         else
            find(m, n + 1);

         sudo[m][n] = 0;
         rowbit[m] &= ~(1 << (i - 1));
         colbit[n] &= ~(1 << (i - 1));
         squarebit[((m + 2) / 3)][((n + 2) / 3)] &= ~(1 << (i - 1));
      }
   }
   else
   {
      if(n == 9)
         find(m + 1, 1);
      else
         find(m, n + 1);
   }
}

int main()
{
   int i, j;

   for(i = 1; i <= 9; i++)
   {
      for(j = 1; j <= 9; j++)
      {
         scanf("%d", &sudo[i][j]);
         rowbit[i] |= (1 << (sudo[i][j] - 1));
         colbit[j] |= (1 << (sudo[i][j] - 1));
         squarebit[((i + 2) / 3)][((j + 2) / 3)] |= (1 << (sudo[i][j] - 1));
      }
   }
   greedyAns();
   find(1, 1);
}
