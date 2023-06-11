#include <cstdio>

const int MAXN = 10;
const int TOGGLE = (1 << 31);
int num[MAXN], sortedTemp[MAXN];

// over-engineering
void radixSort(int* num, int size)
{
	const int MAX_CNT = 256;
	const int MASK = (1 << 8) - 1;
	int cnt[MAX_CNT];

	for (int i = 0; i < size; ++i)
		sortedTemp[i] = num[i] ^ TOGGLE;

	int* t, *n = num, *s = sortedTemp;

	for(int i = 0; i < 32; i += 8)
	{
		for (int j = 0; j < MAX_CNT; ++j)
			cnt[j] = 0;
		for (int j = 0; j < size; ++j)
			cnt[((s[j] >> i) & MASK)]++;
		for (int j = 1; j < MAX_CNT; ++j)
			cnt[j] += cnt[j - 1];
		for (int j = size - 1; j >= 0; --j)
			n[--cnt[((s[j] >> i) & MASK)]] = s[j];

		t = s, s = n, n = t;
	}
}

int main()
{
	int tc;
	scanf("%d\n", &tc);

	while(tc--)
	{
		for (int i = 0; i < 10; ++i)
			scanf("%d", &num[i]);
		radixSort(num, 10);
		printf("%d\n", sortedTemp[7] ^ TOGGLE);
	}
	return 0;
}