#include <cstdio>
#define MAXN	(100000 + 1)

char r[MAXN];
int idx, nCurBar, nBarTotal;

int main(void)
{
	while ((r[idx] = getchar()) != '\n' && r[idx] != EOF)
	{
		if (r[idx] == '(')
			nCurBar++;
		else // guaranteed ')'
		{
			nCurBar--;
			if (idx > 0 && r[idx - 1] == '(') // laser
				nBarTotal += nCurBar;
			else
				nBarTotal++;
		}
		idx++;
	}
	printf("%d", nBarTotal);
	return 0;
}