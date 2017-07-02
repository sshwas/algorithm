#include <cstdio>
#include <cstring>

char chk[2501][2501];
int d[2501];
char s[2502];

int main() 
{
   int n, i, j, k;
   scanf("%s", s + 1);
   n = strlen(s + 1);
   for(i = 1; i <= n; i++)
      chk[i][i] = 1;

   for(i = 1; i <= n - 1; i++)
      if(s[i] == s[i + 1])
         chk[i][i + 1] = 1;

   for(k = 2; k<n; k++)
   {
      for(i = 1; i <= n - k; i++)
      {
         j = i + k;
         chk[i][j] = (s[i] == s[j] && chk[i + 1][j - 1]);
      }
   }

   d[0] = 0;
   for(i = 1; i <= n; i++)
   {
      d[i] = -1;
      for(j = 1; j <= i; j++)
      {
         if(chk[j][i])
         {
            if(d[i] == -1 || d[i] > d[j - 1] + 1)
            {
               d[i] = d[j - 1] + 1;
            }
         }
      }
   }
   printf("%d\n", d[n]);
   return 0;
}