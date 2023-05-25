#include <cstdio>

#define MAX(a,b)	((a) > (b) ? (a) : (b))

const int LM = 10001;

class BigInt
{
public:
	int len = 0;
	int num[LM + 2] = { 0, };
	void init(char str[LM])
	{
		char* s = str;
		while (*s++ != 0) len++;
		for(int i=0; i < len; ++i)
			num[i] = str[len - i - 1] - '0';
	}

	BigInt operator+(BigInt& r)
	{
		BigInt result = { MAX(len, r.len), };
		for (int i = 0; i < result.len; ++i)
		{
			result.num[i] += num[i] + r.num[i];
			result.num[i + 1] = (result.num[i] / 10);
			result.num[i] %= 10;
		}
		if (result.num[result.len]) result.len++;
		return result;
	}

	void printNum()
	{
		for (int i = len - 1; i >= 0; --i)
			printf("%d", num[i]);
	}
};

int main(void)
{
	char x[LM];
	char y[LM];
	scanf("%s", &x);
	scanf("%s", &y);

	BigInt b1, b2;
	b1.init(x);
	b2.init(y);

	BigInt sum = b1 + b2;
	sum.printNum();

	return 0;
}