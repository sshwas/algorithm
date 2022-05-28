#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>

const int MAXN = 100000;
const int MAX_CNT = 256;
const int BIT_MASK = (1 << 8) - 1;

int cnt[MAX_CNT];
int sorted[MAXN];

void radix(int* arr)
{
	int* t;
	int* s = sorted;
	int* a = arr;

	for (int i = 0; i < 32; i += 8)
	{
		for (int j = 0; j < MAX_CNT; j++)
			cnt[j] = 0;

		for (int j = 0; j < MAXN; j++)
			cnt[(a[j] >> i) & BIT_MASK]++;

		for (int j = 1; j < MAX_CNT; j++)
			cnt[j] += cnt[j - 1];

		for (int j = MAXN - 1; j >= 0; j--)
			s[--cnt[(a[j] >> i) & BIT_MASK]] = a[j];

		t = s, s = a, a = t;
	}
}

int notSorted[MAXN];

int main()
{
	for (int i = 0; i < MAXN; i++)
		notSorted[i] = MAXN - i;

	radix(notSorted);

	return 0;
}
