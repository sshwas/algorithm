#include <cstdio>
#define MAX_NUM				(300)
#define MAX_DIGIT			(100)
#define MAX(a,b)			((a) > (b) ? (a) : (b))

int NumOfBeads, NumOfGroup, data[MAX_NUM];

bool CanItBeDivided(int ThresholdOfSum)
{
	int sum = 0, group = 1;
	for (int i = 0; i < NumOfBeads; i++)
	{
		sum += data[i];
		if (sum > ThresholdOfSum)
		{
			sum = data[i];
			group++;
		}
	}
	return (group <= NumOfGroup);
}

int main(void)
{
	scanf("%d %d", &NumOfBeads, &NumOfGroup);

	// sum's range 0 ~ (300 * 100)
	int low = 0, mid, high = (MAX_NUM * MAX_DIGIT);
	for (int i = 0; i < NumOfBeads; i++)
	{
		scanf("%d", &data[i]);
		low = MAX(data[i], low);
	}

	while (low <= high)
	{
		mid = (low + high) / 2;
		CanItBeDivided(mid) ? high = mid - 1 : low = mid + 1;
	}
	printf("%d\n", low);

	// at this time, low is the minimum value among the maximum partial sum values.
	int sum = 0, tBeads = 0;
	for (int i = 0; i < NumOfBeads; i++)
	{
		sum += data[i];
		if (sum > low)
		{
			sum = data[i];
			NumOfGroup--;
			printf("%d ", tBeads);
			tBeads = 0;
		}
		tBeads++;
		if ((NumOfBeads - i) == NumOfGroup)
			break;
	}
	while (NumOfGroup--)
	{
		printf("%d ", tBeads);
		tBeads = 1;
	}
	return 0;
}