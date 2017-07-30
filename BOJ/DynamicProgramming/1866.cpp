#include <iostream>
#include <algorithm>
#define MXN    3001
using namespace std;
int a[MXN], d[MXN], s[MXN];
int main() 
{
   int n, w, h;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
      scanf("%d", &a[i]);

   scanf("%d %d", &w, &h);
   sort(a + 1, a + n + 1);
   
   for(int i = 1; i <= n; i++)
      s[i] = s[i - 1] + a[i];

   for(int i = 1; i <= n; i++)
   {
      d[i] = d[i - 1] + (a[i] * w);
      for(int j = i; j >= 1; j--)
      {
         int c = h;
         int x = (i + j) / 2;
         c += ((s[i] - s[x - 1]) - a[x] * (i - x + 1)) * w;
         c += (a[x] * (x - j + 1) - (s[x] - s[j - 1])) * w;
 
         if(d[i] > d[j - 1] + c)
            d[i] = d[j - 1] + c;
      }
   }
   printf("%d", d[n]);
   return 0;
}