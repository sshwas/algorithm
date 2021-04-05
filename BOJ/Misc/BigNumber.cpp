#include <cstdio>
#include <string>

#define MAX 30    /* (10^MAX - 1) * (10^MAX - 1) ���� ���˴ϴ�. */

int main(void)
{
	char num[2][MAX + 1], *ptr;
	unsigned char mul[MAX + MAX + 2];
	int count, len[2], mul_len, i, j, k;

	for (count = 0; count < 2; )
	{
		printf("����%d �Է�(%d�ڸ� ����) : ", count + 1, MAX);
		scanf("%s", num[count]);
		ptr = num[count];
		while (*ptr) if (*ptr < '0' || *ptr > '9') break; else ptr++;

		if (*ptr) printf("�ٽ� �Է��ϼ���.\n"); else { len[count] = strlen(num[count]); ++count; }
	}

	mul_len = len[0] + len[1]; /* �̰� ������ �ڸ����Դϴ�. ���� ���̴� �̰ź��� 1 ŭ */

	memset(mul, 0x00, mul_len + 2); /* mul �迭 �ʱ�ȭ.. */
	for (i = 0; i < len[0]; i++)
		for (j = 0; j < len[1]; j++) /* ������.. ����2���� ������.. */
		{
			k = mul_len - i - j; /* ���ڸ����� ����.. �ø��� ó���� ���ؼ�.. */
			mul[k] += (num[0][len[0] - i - 1] - '0') * (num[1][len[1] - j - 1] - '0'); /* ���� */
			if (mul[k] > 9) { mul[k - 1] += (mul[k] / 10); mul[k] %= 10; } /* �ø��� ó�� */
		}

	for (i = 0; i <= mul_len; i++) mul[i] += '0';  /* mul �迭�� ����ȭ */
	for (i = 0; mul[i] == '0'; ) i++; /* ���ڸ��� 0 �̸� ��¿��� �����ϱ� ���ؼ� */
	printf("%s * %s\n= %s\n", num[0], num[1], &mul[i]);

	return 0;
}