#include <stdio.h>
#define MAX_SIZE			(10)
#define DIRECTION_TYPE_CNT	(4)

int N, dist;
int maze[(MAX_SIZE + 2)][(MAX_SIZE + 2)], dir[DIRECTION_TYPE_CNT], diridx, curx, cury;
const int mov[5][2] = { {0,0}, {1,0}, {0,-1}, {-1,0}, {0,1} };
bool isDone;

void move(int direction)
{
	int dx = mov[direction][0];
	int dy = mov[direction][1];

	// check if you cannot go straight any more.
	if (maze[curx + dx][cury + dy] == 1)
	{
		isDone = true;
	}
	else
	{
		while (maze[curx + dx][cury + dy] == 0)
		{
			maze[curx][cury] = 1;
			curx += dx;
			cury += dy;
			dist++;
		}
		// loop (dir[0] -> dir[1] -> dir[2] -> dir[3])
		diridx = (diridx + 1) % DIRECTION_TYPE_CNT;
	}
}

int main(void)
{
	dist = diridx = 0;
	curx = cury = 1;
	isDone = false;

	// maze size
	scanf("%d", &N);

	for (int i=0; i<=(N+1); i++)
	{
		for (int j=0; j<=(N+1); j++)
		{
			if ((i==0) || (i==N+1) || (j==0) || (j==N+1))
			{
				// indicates wall outside original maze
				maze[i][j] = 1;
				continue;
			}
			else
			{
				scanf("%1d", &maze[i][j]);
			}
		}
	}

	for (int i = 0; i < DIRECTION_TYPE_CNT; i++)
	{
		scanf("%1d", &dir[i]);
	}

	while (!isDone)
	{
		move(dir[diridx]);
	}
	
	printf("%d\n", dist);

	return 0;
}