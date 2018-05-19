#include <cstdio>

#define MAX_NUM		(52)

typedef struct { int x; int y; } PAIR;
int head, tail, Needed;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
PAIR queue[(MAX_NUM * MAX_NUM)];
char land[MAX_NUM][MAX_NUM];

void enqueue(PAIR t)
{
	queue[head++] = t;
	head = head % MAX_NUM;
}

PAIR dequeue()
{
	PAIR t = queue[tail++];
	tail = tail % MAX_NUM;
	return t;
}

void BFS(PAIR p)
{
	int tx, ty;
	enqueue(p);
	while (head != tail)
	{
		PAIR p2 = dequeue();
		tx = p2.x, ty = p2.y;
		for (int i = 0; i<4; i++)
			if(land[tx + dx[i]][ty + dy[i]])
				land[tx + dx[i]][ty + dy[i]] = 0, enqueue({ tx + dx[i], ty + dy[i] });
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);
		while(k--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			land[y+1][x+1] = 1;
		}
		head = tail = Needed = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (land[i][j])
				{
					land[i][j] = 0;
					BFS({ i, j });
					Needed++;
				}
			}
		}
		printf("%d\n", Needed);
	}
	return 0;
}