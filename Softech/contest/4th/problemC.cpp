// ***main***
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

#define GO 0
#define TURN 1
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define MAXN 200

static int N, C, P, Q;
static int map[MAXN][MAXN];
static int pos_Y, pos_X, Dir;
static int querycount;

struct Position {
	int y, x, dir;
};

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

extern void  userInit(int N, int map[MAXN][MAXN]);
extern Position pos_search();

void identify(int minimap[4][4])
{
	++querycount;
	if (Dir == UP)
		for (int i = 0; i <= 3; ++i)
			for (int j = 0; j <= 3; ++j)
				minimap[i][j] = map[pos_Y + i - 1][pos_X + j - 1];

	else if (Dir == RIGHT)
		for (int i = 0; i <= 3; ++i)
			for (int j = 0; j <= 3; ++j)
				minimap[i][j] = map[pos_Y + j - 1][pos_X - i + 2];

	else if (Dir == DOWN)
		for (int i = 0; i <= 3; ++i)
			for (int j = 0; j <= 3; ++j)
				minimap[i][j] = map[pos_Y - i + 2][pos_X - j + 2];

	else if (Dir == LEFT)
		for (int i = 0; i <= 3; ++i)
			for (int j = 0; j <= 3; ++j)
				minimap[i][j] = map[pos_Y - j + 2][pos_X + i - 1];
}

bool possible(int y, int x) {
	if (map[y][x] == -1) return false;
	if (map[y + 1][x] == -1) return false;
	if (map[y][x + 1] == -1) return false;
	if (map[y + 1][x + 1] == -1) return false;
	return true;
}

bool moving(int method)
{
	int ny, nx;

	++querycount;
	if (method == GO) 
	{
		ny = pos_Y + dy[Dir];
		nx = pos_X + dx[Dir];
		if (!possible(ny, nx))
			return false;
		pos_Y = ny; pos_X = nx;
	}
	else if (method == TURN) 
	{
		Dir = (Dir + 1) % 4;
	}
	return true;
}

static void init()
{
	querycount = 0;
	int user_map[MAXN][MAXN];

	for (int i = 1; i < N - 1; ++i)
		for (int j = 1; j < N - 1; ++j)
			map[i][j] = 0;

	for (int i = 0; i < N; ++i)
		map[i][0] = map[0][i] = map[i][N - 1] = map[N - 1][i] = -1;

	for (int i = 0; i < C; ++i) {
		int y = rand() % (N - 3) + 1;
		int x = rand() % (N - 3) + 1;

		map[y][x] = map[y + 1][x] = map[y][x + 1] = map[y + 1][x + 1] = -1;
	}

	for (int i = 1; i < N - 1; ++i)
		for (int j = 1; j < N - 1; ++j)
			if (map[i][j] == 0)
				map[i][j] = rand() % 100 / (100 - P);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			user_map[i][j] = map[i][j];

	userInit(N, user_map);
}

static bool play()
{
	querycount = 0;
	for (int q = 0; q < Q; ++q) {
		while (1) {
			pos_Y = rand() % (N - 3) + 1;
			pos_X = rand() % (N - 3) + 1;
			Dir = rand() % 4;
			if (possible(pos_Y, pos_X)) break;
		}

		Position ans = pos_search();
		if (ans.y != pos_Y || ans.x != pos_X || ans.dir != Dir)
			return false;
	}

	return true;
}

int main() {
	int TC, SEED;
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d %d", &SEED, &TC);
	srand(SEED);

	int totalscore = 0;
	for (int tc = 1; tc <= TC; ++tc) {
		int score;
		scanf("%d %d %d %d", &N, &C, &P, &Q);

		init();
		if (play() == true && querycount <= Q * N)
			score = 100;
		else
			score = 0;

		printf("#%d %d\n", tc, score);
		totalscore += score;
	}
	printf("total score = %d\n", totalscore / TC);
	return 0;
}

//***user.cpp*** 

//--- if files are separated, followings are needed.
/*
struct Position {
	int y, x, dir;
};

extern void identify(int minimap[4][4]);
extern bool moving(int method);

int N, map[MAXN][MAXN];
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };
*/

struct Position q[(MAXN * MAXN * 4)];
int key[MAXN][MAXN][4];

void SetKeyForWholeMap(int sy, int sx)
{
	int y, x, d;
	for (d = 0; d < 4; d++) 
		key[sy][sx][d] = 0;
	for (y = sy - 1; y <= sy + 2; y++)
		for (x = sx - 1; x <= sx + 2; x++)
			key[sy][sx][0] = key[sy][sx][0] * 3 + map[y][x];
	for (x = sx + 2; x >= sx - 1; x--)
		for (y = sy - 1; y <= sy + 2; y++)
			key[sy][sx][1] = key[sy][sx][1] * 3 + map[y][x];
	for (y = sy + 2; y >= sy - 1; y--)
		for (x = sx + 2; x >= sx - 1; x--)
			key[sy][sx][2] = key[sy][sx][2] * 3 + map[y][x];
	for (x = sx - 1; x <= sx + 2; x++)
		for (y = sy + 2; y >= sy - 1; y--)
			key[sy][sx][3] = key[sy][sx][3] * 3 + map[y][x];
}

void userInit(int n, int Map[MAXN][MAXN]) 
{
	//--- if files are separated, followings are needed.
	/*
	N = n;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) 
			map[y][x] = Map[y][x];
	*/

	for (int y = 1; y <= N - 3; y++) 
		for (int x = 1; x <= N - 3; x++)
			SetKeyForWholeMap(y, x);
}

int GetKeyOnCurrentPosition()
{
	int bike[4][4], bikekey = 0;
	identify(bike);
	// caculate bike key on current 4x4 cube associated with Dir
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++) 
			bikekey = bikekey * 3 + bike[y][x];

	return bikekey;
}

Position pos_search()
{
	int bikekey = GetKeyOnCurrentPosition();
	int y, x, d, i, j, head, tail = 0;
	for (y = 1; y <= N - 3; y++) 
	{
		for (x = 1; x <= N - 3; x++)
		{
			for (d = 0; d < 4; d++) 
			{
				if (key[y][x][d] == bikekey) 
				{
					q[tail].y = y, q[tail].x = x, q[tail].dir = d;
					tail++;
				}
			}
		}
	}

	while (tail != 1) 
	{
		for (i = 0; i < 4; i++)
		{
			if (moving(GO)) 
				break;
			moving(TURN);
			for (j = 0; j < tail; j++) 
				q[j].dir = (q[j].dir + 1) % 4;
		}
		bikekey = GetKeyOnCurrentPosition();
		head = 0;
		for (i = 0; i < tail; i++)
		{
			d = q[i].dir;
			y = q[i].y + dy[d], x = q[i].x + dx[d];
			if (key[y][x][d] == bikekey) 
			{
				q[head].y = y, q[head].x = x, q[head].dir = d;
				head++;
			}
		}
		tail = head;
	}
	return q[0];
}