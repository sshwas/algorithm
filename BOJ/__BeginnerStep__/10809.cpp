#include <cstdio>
#define NUM_OF_ALPHABET 26
int main()
{
   char c;
   int i=0, cnt[NUM_OF_ALPHABET];
   for(i = 0; i < NUM_OF_ALPHABET; i++)
      cnt[i] = -1;
   i = 0;
   while((c = getchar()) != '\n' && c != EOF)
   {
      if(cnt[(c - 'a')] == -1)
         cnt[(c - 'a')] = i;
      i++;
   }
   for(i = 0; i < NUM_OF_ALPHABET; i++)
      printf("%d ", cnt[i]);
}