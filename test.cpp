#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX 128 

static char org[MAX + 1][MAX + 1];
static char dmg[MAX + 1][MAX + 1];
//static char res[MAX + 1][MAX + 1];
static int cnt[MAX + 1][MAX + 1];
static int N, Query_Cnt;

extern void restore(int n, char dmg[][MAX + 1]);

int Query(int sy, int sx, int len)
{
	if (Query_Cnt > N * 9 || sy + len > MAX || sx + len > MAX) return -1;
	Query_Cnt++;
	int ey = sy + len, ex = sx + len;
	return cnt[ey][ex] - cnt[sy + len][sx] - cnt[sy][sx + len] + cnt[sy][sx];
}

static void init()
{
	int i, j, M, y, x;
	Query_Cnt = 0;
	N = rand() % 50 + 79;//scanf("%d", &N); 
	for (i = 0; i <= MAX; i++) for (j = 0; j <= MAX; j++)
		dmg[i][j] = org[i][j] = cnt[i][j] = 0;

	for (i = 0; i < N; i++) for (j = 0; j < N; j++)
		org[i][j] = dmg[i][j] = '0';

	M = rand() % (N / 2) + N / 2;
	for (i = 0; i < M; i++) {
		y = rand() % N; x = rand() % N;
		org[y][x] = dmg[y][x] = '1';
	}
	for (i = 0; i < N; i++) {
		//scanf("%s", &org[i]); 
		//strcpy(dmg[i], org[i]); 
		for (j = 0; j < N; j++) cnt[i + 1][j + 1] = org[i][j] - 48;
	}
	M = rand() % (N / 2) + N / 2;
	for (i = 0; i < M; i++) {
		y = rand() % N; x = rand() % N;
		dmg[y][x] = '1';
	}
	for (i = 1; i <= MAX; i++) {
		for (j = 1; j <= MAX; j++) cnt[i][j] += cnt[i][j - 1];
		for (j = 1; j <= MAX; j++) cnt[i][j] += cnt[i - 1][j];
	}
}

static int check()
{
	for (int i = 0; i < N; i++) {
		if (strcmp(org[i], dmg[i])) return 0;
	}
	return 100;
}

int main()
{
	srand(12345);
	int T = 100, score;
	//scanf("%d", &T); 
	for (int tc = 0; tc < T; tc++) {
		init();
		restore(N, dmg);
		score = check();
		printf("#%d : %d\n", tc + 1, score);
	}
	return 0;
}

int rcnt[MAX + 1][MAX + 1];
int rr[4] = { 0, 0, 1, 1 }, cc[4] = { 0, 1, 0, 1 };

int find(char dmge[][MAX + 1], int r, int c, int len)
{
	int orcnt = Query(r, c, len), recnt = 0, m = len / 2;
	int dmcnt = rcnt[r + len][c + len] - rcnt[r][c + len] - rcnt[r + len][c] + rcnt[r][c];
	if (orcnt == dmcnt) return 0;
	if (len < 2) {
		dmge[r][c] = '0';
		return 1;
	}
	for (int i = 0; i < 4 && dmcnt - orcnt > recnt; i++) {
		recnt += find(dmge, r + rr[i] * m, c + cc[i] * m, m);
	}
	return recnt;
}

void restore(int n, char dmge[][MAX + 1])
{
	int i, j, k = 1;
	for (i = 1; i <= MAX; i++) for (j = 1; j <= MAX; j++) rcnt[i][j] = 0;
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) rcnt[i + 1][j + 1] = dmge[i][j] - 48;
	for (i = 1; i <= MAX; i++) {
		for (j = 1; j <= MAX; j++) rcnt[i][j] += rcnt[i][j - 1];
		for (j = 1; j <= MAX; j++) rcnt[i][j] += rcnt[i - 1][j];
	}
	while (k < n) k <<= 1;
	find(dmge, 0, 0, k);
}