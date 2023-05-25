#include <cstdio>

const int LM = 1001;

class BigInt
{
public:
	int len = 0;
	int num[LM + LM + 2] = { 0, };
	BigInt(char str[LM])
	{
		while (*str != 0)
		{
			num[len++] = *str++ - '0';
		}
	}
};

int main(void)
{
	char x[LM];
	char y[LM];
	scanf("%s", &x);
	scanf("%s", &y);


	return 0;
}