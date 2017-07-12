// Cow Sorting

#include <cstdio>
#include <algorithm>
using namespace std;

const int MXN = 10000;
pair<int,int> a[MXN + 1];
char chk[MXN + 1];

int main()
{
   int n;
   scanf("%d", &n);
   // a[].first = data, a[].second = index
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &a[i].first);
      a[i].second = i;
   }
   sort(a, a + n);

   long long ans = 0;
   for (int i = 0; i < n; i++)
   {
      if (chk[i])
         continue;
      int cycle = 0;
      // loop 1 cycle, cycle = the # of vertices in a cycle
      for (int j = i; !chk[j]; j = a[j].second)
      {
         cycle++;
         ans += a[j].first;
         chk[j]++;
      }
      // case 1 : check only non-sorted cyclic vertices
      //          4 2 1 3 -> check (1,3,4) -> (1+3) + (1+4) = 9
      // case 2 : check a vertex having minimum value in the graph and non-sorted cyclic vertices
      //          1 8 9 7 6 -> check (1) and (8,9,7,6) -> (1+6) + (1+9) + (1+7) + (1+8) + (1+6) = 41
      ans += min((cycle - 2) * a[i].first, a[i].first + (cycle + 1) * a[0].first);
   }
   printf("%lld", ans);
   return 0;
}