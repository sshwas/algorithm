/* (jungol.co.kr) 1972 : ����(sort)

ù �ٿ� N�� �־�����. N�� ���� �� �ڿ����� �����̴�. (1��N��100,000)
���Ĺ�� C�� �־�����. C���� 0�̸� ��������, 1�̸� ������������ ����ؾ��Ѵ�.
N���� �ڿ����� �־�����. �� �ڿ����� 10�� ������ ���̴�.
*/

#include <stdio.h>

int N, order, num[100001];

void swap( int *a, int *b )
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int partition( int low, int high )
{
   int i, j;
   i = low - 1;
   for( j = low; j <= high-1; j++ )
   {
      if( (num[j] <= num[high] && order==0) ||
          ( num[j] >= num[high] && order == 1 ))
      {
         i++;
         swap( &num[i], &num[j] );
      }
   }
   swap( &num[i+1], &num[high] );
   return i+1;
}

void quicksort( int low, int high )
{
   int pivot;
   if( low < high )
   {
      pivot = partition( low, high );

      quicksort( low, pivot - 1 );
      quicksort( pivot + 1, high );
   }
}

int main()
{
   int i;
   scanf( "%d %d", &N, &order );

   for( i = 0; i < N; i++ )
   {
      scanf( "%d", &num[i] );
   }
   quicksort( 0, N - 1 );

   for( i = 0; i < N; i++ )
   {
      printf( "%d\n", num[i] );
   }
}