#include<iostream>
using namespace std;
#define MAXN		(2000000 + 2)

int N, D, maxcnt, head, tail, freeidx;
long long P, S[MAXN], M[MAXN], Mdesc[MAXN];

int main(void)
{
	int t, s, e;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++)
	{
		scanf("%d %lld %d", &N, &P, &D);
		S[0] = M[0] = 0;
		maxcnt = D;
		for (int i = 1; i <= N; i++)
		{
			scanf("%lld", &S[i]);
			S[i] += S[i - 1];
		}
		for (int i = 1; i <= (N - D + 1); i++)
		{
			M[i] = S[i + D - 1] - S[i - 1];
		}
		s = 1, freeidx = 1;
		head = 0, tail = 1;
		Mdesc[head] = M[freeidx];
		while ((s + maxcnt - 1) <= N)
		{
			e = s + maxcnt - 1;
			if ((S[e] - S[s - 1] - Mdesc[head]) <= P)
			{
				maxcnt++;
			}
			else
			{
				if (Mdesc[head] == M[s])
					head++;
				s++;
			}
			freeidx++;
			for (int i = tail - 1; i >= head; i--)
			{
				if (Mdesc[i] < M[freeidx])
					tail--;
				else
					break;
			}
			Mdesc[tail] = M[freeidx];
			tail++;
		}
		printf("#%d %d\n", tc, maxcnt - 1);
	}
	return 0;
}