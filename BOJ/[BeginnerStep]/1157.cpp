#include <cstdio>
#include <cstring>

int main()
{
   int alpha[27] = {0, }, idx, max = 0, i, len;
   char str[1000001], dup = 0;
   scanf("%s", str);
   len = strlen(str);
   for(i = 0; i < len; i++)
   {
      if(str[i] >= 'a')
         alpha[str[i] - 'a']++;
      else
         alpha[str[i] - 'A']++;
   }
   for(i = 0; i < 27; i++)
   {
      if(alpha[i] == max)
         dup = 1;
      else if(alpha[i] > max)
      {
         max = alpha[i];
         idx = i;
         dup = 0;
      }
   }
   printf("%c", (dup ? '?' : 'A' + idx));
}