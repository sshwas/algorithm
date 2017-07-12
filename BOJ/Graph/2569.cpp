#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct vertex
{
   int data, index;
   bool operator < (const vertex& v1)const{ return data < v1.data;  }
} V;

const int MXN = 1000;
V a[MXN + 1];
char chk[MXN + 1];

int main()
{
   int n;
   scanf("%d", &n);
   for(int i = 0; i < n; i++)
   {
      scanf("%d", &a[i].data);
      a[i].index = i;
   }
   sort(a, a + n);

   long long ans = 0;
   for(int i = 0; i < n; i++)
   {
      if(chk[i])
         continue;
      int cycle = 0;
      for(int j = i; !chk[j]; j = a[j].index)
      {
         cycle++;
         ans += a[j].data;
         chk[j]++;
      }
      ans += min( (cycle-2) * a[i].data , a[i].data + (cycle+1) * a[0].data );
   }
   printf("%d", ans);
   return 0;
}