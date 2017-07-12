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
      // case 1 : check only non-sorted cyclic vertices
      //          4 2 1 3 -> check (1,3,4) -> (1+3) + (1+4) = 9
      // case 2 : check a vertex having minimum value in the graph and non-sorted cyclic vertices
      //          1 8 9 7 6 -> check (1) and (8,9,7,6) -> (1+6) + (1+9) + (1+7) + (1+8) + (1+6) = 41
      ans += MIN( (cycle-2) * a[i].data , a[i].data + (cycle+1) * a[0].data );
   }
   printf("%lld", ans);
   return 0;
}