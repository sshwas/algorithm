#include <stdio.h>

#define MAXNUM 1001

int N, M, head, tail;
int queue[MAXNUM];
int graph[MAXNUM][MAXNUM];
int isVisited[MAXNUM];

int isEmpty()
{
   return (head == tail);
}

void enqueue(int n)
{
   queue[head++] = n;
   head = head % MAXNUM;
}

int dequeue()
{
   int ret;
   if(isEmpty())
      return -1;
   else
   {
      ret = queue[tail++];
      tail = tail % MAXNUM;
      return ret;
   }
}

void DFS(int v)
{
   int i;
   if(isVisited[v])
      return;
   printf("%d ", v);
   isVisited[v] = true;

   for(i = 1; i <= N; i++)
      if(graph[v][i])
         DFS(i);
}

void BFS(int v)
{
   int i, val;
   enqueue(v);
   isVisited[v] = true;
   
   while(!isEmpty())
   {
      val = dequeue();
      printf("%d ", val);

      for(i = 1; i <= N; i++)
      {
         if(graph[val][i] && !isVisited[i])
         {
            enqueue(i);
            isVisited[i] = true;
         }
      }
   }
}

int main()
{
   int V, v1, v2, i;
   scanf("%d %d %d", &N, &M, &V);
   while(M--)
   {
      scanf("%d %d", &v1, &v2);
      graph[v1][v2] = graph[v2][v1] = 1;  // adjacent matrix
   }

   DFS(V);

   // initialization
   for(i = 1; i <= N; i++)
      isVisited[i] = false;

   printf("\n");
   BFS(V);
}