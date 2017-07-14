#include <cstdio>

int c, tree[300001][3];

int main()
{
   int n, root;
   scanf("%d", &n);
   scanf("%d", &root);
   tree[root][0] = root;
   n--;
   printf("%d\n", c);
   while(n--)
   {
      int i, x, p;
      scanf("%d", &x);
      for(i = tree[root][0]; i; c++)
      {
         p = i;
         if(i > x)
         {
            i = tree[i][1];
         }
         else
         {
            i = tree[i][2];
         }
      }
      tree[p][(p<x ? 2 : 1)] = x;
      tree[x][0] = x;
      printf("%d\n", c);
   }
   return 0;
}