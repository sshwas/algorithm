#include <cstdio>
#define MAX(a, b)	((a)>(b) ? (a) : (b))
#define MAXN		(2000000 + 2)

int N, D, A[MAXN], S[MAXN], M[MAXN], maxcnt;
long long P;

void go(int s, int e, int free)
{
	if (s == 0 || e > N || free > (e - D + 1))
		return;
	int sum = S[e] - S[s - 1];
	int minus = M[free];
	if ((sum - minus) <= P)
	{
		maxcnt = MAX(maxcnt, (e - s + 1));
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc<=t; tc++)
	{
		scanf("%d %d %d", &N, &P, &D);
		A[0] = A[N + 1] = 0;
		maxcnt = D;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &A[i]);
			S[i] = S[i - 1] + A[i];
		}
		for (int i = 1; i <= (N - D + 1); i++)
		{
			M[i] = S[i + D - 1] - S[i - 1];
		}
		go(1, D + 1, 1);
		printf("#%d %d\n", tc, maxcnt);
	}
	return 0;
}