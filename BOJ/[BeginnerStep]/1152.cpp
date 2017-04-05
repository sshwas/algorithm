#include <cstdio>

int main() {
   int n=0;
   char tmp,prev = ' ';

   while((tmp = getchar()) != '\n' && tmp != EOF)
   {
      if(prev == ' ' && tmp != ' ')
         n++;
      prev = tmp;
   }
   printf("%d", n);
}