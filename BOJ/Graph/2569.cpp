#include <cstdio>

#define MIN(a,b)  ((a)<(b) ? (a):(b))
typedef struct vertex
{
   int data, index;
} V;

const int MXN = 1000;
V a[MXN + 1];
char chk[MXN + 1];

void swap(V *v1, V *v2)
{
   V t = *v1;
   *v1 = *v2, *v2 = t;
}

int main()
{
   int n;
   scanf("%d", &n);
   for(int i = 0; i < n; i++)
   {
      scanf("%d", &a[i].data);
      a[i].index = i;
   }

   // bubble sort in ascending order of a[].data
   for (int i = 0; i < n - 1; i++)
      for (int j = 0; j < n - i - 1; j++)
         if (a[j].data > a[j + 1].data)
            swap(&a[j], &a[j + 1]);

   long long ans = 0;
   for(int i = 0; i < n; i++)
   {
      if(chk[i])
         continue;
      int cycle = 0;
      // loop 1 cycle, cycle = the # of vertices in a cycle
      for(int j = i; !chk[j]; j = a[j].index)
      {
         cycle++;
         ans += a[j].data;
         chk[j]++;
      }
      ans += MIN( (cycle-2) * a[i].data , a[i].data + (cycle+1) * a[0].data );
   }
   printf("%lld", ans);
   return 0;
}