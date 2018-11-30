#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128

static char org[MAX + 1][MAX + 1];
static char dmg[MAX + 1][MAX + 1];
static int N, Query_Cnt;

extern void restore(int n, char dmg[][MAX + 1]);

int Query(int sy, int sx, int len)  // 실제 채점할 때에는 더 빠른 코드로 실행합니다.
{
	if (Query_Cnt > N * 10 || sy < 0 || sx < 0 || sy + len > MAX || sx + len > MAX) 
		return -1;
	Query_Cnt++;
	int i, j, subcnt = 0;
	for (i = 0; i < len; i++)
		for (j = 0; j < len; j++)
		{
			subcnt += org[sy + i][sx + j];
		}
	return subcnt;
}

static void init()
{
	for (int i = 0; i <= MAX; i++)
		for (int j = 0; j <= MAX; j++)
			dmg[i][j] = org[i][j] = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			org[i][j] = dmg[i][j] = rand() % 2;
}

static void substitute(int type)
{
	for (int i = 0; i < N * 3 / 2; i++)
	{
		org[rand() % N][rand() % N] = type;
	}
}

static int check()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (org[i][j] != dmg[i][j]) 
				return 0;
	return 100;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int T, seed, score;
	scanf("%d %d %d", &T, &seed, &N);
	srand(seed);
	init();
	for (int tc = 0; tc < T; tc++)
	{
		Query_Cnt = 0;
		substitute(tc % 2);
		restore(N, dmg);
		score = check();
		//printf("%d\n", Query_Cnt);
		if (score == 0) break;
	}
	printf("score : %d\n", score);
	return 0;
}

int rcnt[MAX + 1][MAX + 1];
int dr[4] = { 0, 0, 1, 1 }, dc[4] = { 0, 1, 0, 1 };

int find(char dmge[][MAX + 1], int r, int c, int len)
{
	int orcnt = Query(r, c, len), recnt = 0, m = len / 2;
	int dmcnt = rcnt[r + len][c + len] - rcnt[r][c + len] - rcnt[r + len][c] + rcnt[r][c];
	if (orcnt == dmcnt) 
		return 0;
	if (len < 2) 
	{
		dmge[r][c] = (orcnt > dmcnt ? 1 : 0);
		return 1;
	}
	int di = (orcnt > dmcnt ? orcnt - dmcnt : dmcnt - orcnt);
	for (int i = 0; i < 4 && di  > recnt; i++)
	{
		recnt += find(dmge, r + dr[i] * m, c + dc[i] * m, m);
	}
	return recnt;
}

void restore(int n, char dmge[][MAX + 1])
{
	int i, j, k = 1;
	for (i = 1; i <= MAX; i++) 
		for (j = 1; j <= MAX; j++) 
			rcnt[i][j] = 0;
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			rcnt[i + 1][j + 1] = dmge[i][j];
	for (i = 1; i <= MAX; i++) 
	{
		for (j = 1; j <= MAX; j++) 
			rcnt[i][j] += rcnt[i][j - 1];
		for (j = 1; j <= MAX; j++) 
			rcnt[i][j] += rcnt[i - 1][j];
	}
	while (k < n)
		k <<= 1;
	find(dmge, 0, 0, k);
}