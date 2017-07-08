// Elevator problem : resolved with BFS, only <cstdio>
#include <cstdio>

// instead of vector
typedef struct node
{
   int d;
   struct node *next;
} NODE;

const int MXN = 100100;
int go[MXN + 1], dist[MXN + 1], q[MXN + 1], h, t;
NODE adj[MXN + 1];

void add(int idx, int a)
{
   NODE *t = &adj[idx];
   while(t->next != NULL)
      t = t->next;

   if(t->d == 0)
   {
      t->d = a;
      t->next = NULL;
   }
   else
   {
      t->next = new NODE;
      t->next->d = a;
      t->next->next = NULL;
   }
}

/* in this given example,
 elevator   no1 - 4, 7, 10
            no2 - 7, 12
            no3 - 4, 8, 12
 
let's add a dummy node for every evelator as follows
 elevator   no1 13(1+n) - 4, 7, 10
            no2 14(2+n) - 7, 12
            no3 15(3+n) - 4, 8, 12

then, you can make a linked list array for BFS (the last array index will be n + m)
Please note that all the stroies must be conneted with only dummy node.
It means..  the path of (10 to 8) will be 10 - (13) - 4 - (15) - 8.
[4] 13 -> 15
[7] 13 -> 14
[8] 15
[10] 13
[12] 14 -> 15
[13] 4 -> 7 -> 10
[14] 7 -> 12
[15] 4 -> 8 -> 12

if a = 10 and b = 8, it would be better to start with b because it's easier way to track the path.
(Path tree)
           8         depth 1 (dist in the code)
           |
           15        depth 2
          / | 
         4  12       depth 3
       /     |
      13     14      depth 4
     / |
    7  10            depth 5

Also, go[] array has the index of their parent,
go[10] = 13, go[13] = 4, go[4] = 15, go[15] = 8, go[8] = 0
*/
int main()
{
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i = 1, x, y; i <= m; i++)
   {
      scanf("%d %d", &x, &y);
      for(int j = x; j <= n; j += y)
         add((n + i), j), add(j, (n + i));
   }

   int a, b;
   scanf("%d %d", &a, &b);
   for(int i = 1; i <= n + m; i++) 
      dist[i] = -1;

   dist[b] = 0;
   q[t++] = b;
   while(h != t) 
   {
      NODE *node = &adj[q[h]];
      while(1)
      {
         if(dist[node->d] == -1)
         {
            q[t++] = node->d;
            dist[node->d] = dist[q[h]] + 1;
            go[node->d] = q[h];
         }
         if(node->next != NULL)
            node = node->next;
         else
            break;
      }
      h++;
   }
   printf("%d\n", dist[a] / 2);
   for(int i = go[a]; i; i = go[go[i]])
      printf("%d\n", (i - n));
   return 0;
}