#include <cstdio>

#define MAX(a,b)	((a) > (b) ? (a) : (b))

const int LM = 300001;

class BigInt
{
public:
	int len = 0;
	int num[LM + LM + 2] = { 0, };
	void init(char str[LM])
	{
		char* s = str;
		while (*s++ != 0) len++;
		for (int i = 0; i < len; ++i)
			num[i] = str[len - i - 1] - '0';
	}

	BigInt* operator*(BigInt& op2)
	{
		BigInt* result = new BigInt();
		if ((len == 1 && num[0] == 0) || (op2.len == 1 && op2.num[0] == 0))
		{
			result->len = 1;
			return result;
		}

		result->len = len + op2.len;
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < op2.len; ++j)
			{
				result->num[i + j] += num[i] * op2.num[j];
			}
		}
		for (int i = 0; i < result->len; ++i)
		{
			result->num[i + 1] += result->num[i] / 10;
			result->num[i] %= 10;
		}
		if (result->num[result->len - 1] == 0) result->len--;
		return result;
	}

	void printNum()
	{
		for (int i = len - 1; i >= 0; --i)
			printf("%d", num[i]);
	}
};


BigInt b1, b2;

int main(void)
{
	char x[LM];
	char y[LM];
	scanf("%s", &x);
	scanf("%s", &y);

	b1.init(x);
	b2.init(y);

	BigInt* mul = b1 * b2;
	mul->printNum();

	return 0;
}