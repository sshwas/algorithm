#include <cstdio>

int main()
{
   int n, ng = 0;
   scanf("%d\n", &n);
   while(n--)
   {
      char s[101] = { 0, };
      int chk[27] = { 0, };
      scanf("%s", s);
      int prev=-1, curr, i;
      for(i = 0; s[i] != '\0'; i++)
      {
         curr = s[i] - 'a';
         if(prev != curr && chk[curr] != 0)
            break;
         chk[curr]++;
         prev = curr;
      }
      if (s[i]=='\0')
         ng++;
   }
   printf("%d", ng);
   return 0;
}