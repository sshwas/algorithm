// Counting sort
#include <cstdio>

int main()
{
   int N, i, mid, many, max, min, index;
   char check = 1, check2 = 1;
   double avg;
   int arr[8001] = {0, };

   avg = 0;
   scanf("%d", &N);
   for(i = 0; i < N; i++)
   {
      int temp;
      scanf("%d", &temp);
      avg += temp;
      arr[temp + 4000]++; //-4000~4000 --> 0~8000
   }
   printf("%.0f\n", avg / N); //arithmetical avg
   mid = (N + 1) / 2;
   many = 0;
   max = -4001; min = 4001;   //range
   for(i = 0; i < 8001; i++)
   {
      if(arr[i] != 0)
      {
         if(arr[i] == many && check2 == 1) // the most frequent value
         {
            index = i - 4000;
            check2 = 0;
         }
         if(arr[i] > many)
         {
            many = arr[i];
            index = i - 4000;
            check2 = 1;
         }
         if((i - 4000) > max) max = i - 4000;
         if((i - 4000) < min) min = i - 4000;
         if(check == 1) mid = mid - arr[i];
         if(mid <= 0 && check == 1)
         {
            mid = i - 4000;
            check = 0;
         }
      }
   }
   printf("%d\n", mid);
   printf("%d\n", index);
   printf("%d\n", max - min);
}