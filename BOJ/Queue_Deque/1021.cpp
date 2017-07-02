// Josephus problem

#include <cstdio>
#include <deque>
using namespace std;

int main()
{
   int N, M, i, tmp;
   deque<int> q;

   scanf("%d %d", &N, &M);
   for(i = 1; i <= N; i++)
      q.push(i);

   printf("<");
   while(q.size() > 1)
   {
      for(i = 0; i < (M - 1); i++)
      {
         tmp = q.front();
         q.pop();
         q.push(tmp);
      }
      tmp = q.front();
      q.pop();
      printf("%d, ", tmp);
   }
   tmp = q.front();
   q.pop();
   printf("%d>", tmp);
}