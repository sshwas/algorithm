#include <cstdio>
#define MAX(a,b)  ((a)>(b)? (a):(b))
typedef struct line
{
   int left;
   int right;
} LINE;

const int MXN = 100;
LINE data[MXN + 1];
int dp[MXN+1];

int main()
{
   int N;
   scanf("%d", &N);
   for(int i = 1; i <= N; i++)
      scanf("%d %d", &data[i].left, &data[i].right);

   // bubble sort
   for(int i = 1; i < N; i++)
      for(int j = 1; j <= N-i; j++)
         if(data[j].left > data[j+1].left)
         {
            LINE temp = data[j];
            data[j] = data[j+1];
            data[j+1] = temp;
         }

   // LIS
   dp[1] = 1;
   for(int i = 2; i <= N; i++)
      for(int j = 1; j < i; j++)
         dp[i] = MAX(dp[i], ((data[j].right < data[i].right) ? dp[j] + 1 : 1));

   int LIS = 0;
   for(int i = 1; i <= N; i++)
      LIS = MAX(LIS, dp[i]);
      
   printf("%d", (N - LIS));
   return 0;
}