#include <cstdio>

const int LM = 81;

int intcmp(int* x, int* y, int len)
{
	while (*x == *y && len--) x++, y++;
	return *x - *y;
}

class BigInt
{
public:
	int len = 0;
	int num[LM] = { 0, };
	void init(char str[LM])
	{
		char* s = str;
		while (*s++ != 0) len++;
		for (int i = 0; i < len; ++i)
			num[i] = str[i] - '0';
	}

	BigInt operator/(BigInt& op2)
	{
		BigInt ret; // ret : ��, this : ������
		for (int i = 0; i <= len - op2.len; ++i)
		{
			// ù��° �ڸ����� ���̸� ���缭 1�� �� �� ������,
			while (intcmp(num + i, op2.num, op2.len) >= 0)
			{
				// ret�� ���� �ڸ����� 1 �����ش�
				ret.num[ret.len]++;

				// ((this(op1)�� ���� �ڸ������� op2���̸�ŭ ��) - op2)�� ����
				for (int j = i + op2.len - 1; j >= i; --j)
				{
					num[j] -= op2.num[j - i];
					if (num[j] < 0)
						num[j] += 10, num[j - 1]--;
				}
			}

			if (num[i])	// ������ ������ ��, ���� ���� �������� �޾Ƴ���
				num[i + 1] += (num[i] * 10), num[i] = 0;
			if (ret.len > 0 || ret.num[ret.len] > 0) // ���� ù��° �ڸ����� 0�� ���� �ʵ���
				ret.len++;

		}

		// ������ ��������
		for (int i = len; i > 0 ; --i)
		{
			num[i - 1] += num[i] / 10;
			num[i] %= 10;
		}
		return ret;
	}

	void printNum()
	{
		bool found = false;
		int idx;
		for (int i = 0; i < len; ++i)
		{
			if (num[i] > 0)
			{
				found = true, idx = i;
				break;
			}
		}

		if (found)
			for (int i = idx; i < len; ++i)
				printf("%d", num[i]);
		else
			printf("0");

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
	int tc;
	scanf("%d\n", &tc);

	for(int i=0 ; i < tc; ++i)
	{
		char x[LM];
		char y[LM];
		scanf("%s", &x);
		scanf("%s", &y);
		int xLen = strlen(x);
		int yLen = strlen(y);

		BigInt b1, b2;
		b1.init(x);
		b2.init(y);

		BigInt div = b1 / b2;
		div.printNum(); // ��
		b1.printNum(); // ������

		printf("\n");
	}

	return 0;
}
