// Jungol 3115 (±ä ÀÚ¸® ³ª´°¼À) ->  BOJ 6974 (Long Division) Ç®¾îº¼ °Í

#include <cstdio>

const int LM = 201;
char ZERO[2] = "0";

int intcmp(int* x, int* y, int len)
{
	while (*x == *y && len--) x++, y++;
	return *x - *y;
}

class BigInt
{
public:
	int len = 0;
	int num[LM] = {0,};
	void init(char str[LM])
	{
		char* s = str;
		while (*s++ != 0) len++;
		for (int i = 0; i < len; ++i)
			num[i] = str[i] - '0';
	}

	BigInt operator/(BigInt& op2)
	{
		BigInt ret;
		for(int i=0; i <= len - op2.len ; ++i)
		{
			while (intcmp(num + i, op2.num, op2.len) >= 0)
			{
				ret.num[ret.len]++;			
				for(int j= i + op2.len - 1 ; j >= i ; --j)
				{
					num[j] -= op2.num[j - i];
					if (num[j] < 0)
						num[j] += 10, num[j - 1]--;
				}
			}
			if (num[i])
				num[i + 1] += (num[i] * 10), num[i] = 0;
			if (ret.len > 0 || ret.num[ret.len] > 0)
				ret.len++;

		}
		return ret;
	}

	void printNum()
	{
		for (int i = 0; i < len; ++i)
			printf("%d", num[i]);
		printf("\n");
	}
};

int strlen(char* s)
{
	int len = 0;
	while (*s++) len++;
	return len;
}

int strcmp(char* x, int xLen, char* y, int yLen)
{
	if (xLen != yLen) return xLen - yLen;

	while (*x && *x == *y) x++, y++;
	return *x - *y;
}

int main(void)
{
	while(true)
	{
		char x[LM];
		char y[LM];
		scanf("%s", &x);
		scanf("%s", &y);
		int xLen = strlen(x);
		int yLen = strlen(y);

		if (strcmp(x, xLen, ZERO, 1) == 0 || strcmp(y, yLen, ZERO, 1) == 0)
		{
			break;
		}

		BigInt b1, b2;
		if (strcmp(x, xLen, y, yLen) < 0)
		{
			b1.init(y);
			b2.init(x);
		}
		else
		{
			b1.init(x);
			b2.init(y);
		}

		BigInt div = b1 / b2;
		div.printNum();
	}

	return 0;
}
