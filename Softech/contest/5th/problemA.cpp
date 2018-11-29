#include <cstdio>
#define MAXN	(50 + 1)

int r[MAXN][MAXN];
int chk[MAXN][MAXN], n,  t;
const int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

void go(int x, int y) 
{
	if (x < 0 || y < 0 || x >= n || y >= n || chk[x][y])
		return;
	chk[x][y] = 1;
	if (r[x][y] == 0)
	{ 
		r[x][y]++;
		return; 
	}
	for (int i = 0; i < 4; i++)
		go(x + dx[i], y + dy[i]);
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &r[i][j]);

	while(!chk[n - 1][n - 1])
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				chk[i][j] = 0;
		go(0, 0);
		t++;
	}
	printf("%d", t - 1);
		
	return 0;
}