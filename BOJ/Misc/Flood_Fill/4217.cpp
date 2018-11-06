// reference : ACM-ICPC 2011 World Finals C
#include <cstdio>

#define MAX_NUM		(203)

const int toBin[16][4] =
	{ { 0,0,0,0 },{ 0,0,0,1 },{ 0,0,1,0 },{ 0,0,1,1 },{ 0,1,0,0 },{ 0,1,0,1 },{ 0,1,1,0 },{ 0,1,1,1 },
	  { 1,0,0,0 },{ 1,0,0,1 },{ 1,0,1,0 },{ 1,0,1,1 },{ 1,1,0,0 },{ 1,1,0,1 },{ 1,1,1,0 },{ 1,1,1,1 } };
const char ancient[7] = "WAKJSD"; // index indicates the number of holes
int arr[MAX_NUM][MAX_NUM]; // input, arr[h][w*4] (0<h<=200, 0<w<=50, w should be changed to Binary)
int CharCnt[6];

int head, tail;
int queue[(MAX_NUM * MAX_NUM)];
int graph[(MAX_NUM * MAX_NUM)][4];
char isVisited[(MAX_NUM * MAX_NUM)];
//int dist[(MAX_NUM * MAX_NUM)];

void enqueue(int x)
{
	queue[tail] = x;
	tail = (tail + 1) % MAX_NUM;
}

int dequeue()
{
	int t = queue[head];
	head = (head + 1) % MAX_NUM;
	return t;
}

void BFS(int s)
{
	enqueue(s);
	isVisited[s] = 1;
	while (head != tail)
	{

	}
}


int main()
{
	int h, w;
	while (scanf("%d %d", &h, &w))
	{
		if (!h && !w)
			break;

		// initialization with zero-padding
		for (int i=1; i<=h+1; i++)
			arr[i][w*4+1] = 0;
		for (int i=1; i<=w*4+1; i++)
			arr[h+1][i] = 0;

		int x;
		for (int i=1; i<=h ; i++)
		{
			for (int j=0; j<w; j++)
			{
				scanf("%1x", &x);
				arr[i][j*4+1] = toBin[x][0];
				arr[i][j*4+2] = toBin[x][1];
				arr[i][j*4+3] = toBin[x][2];
				arr[i][j*4+4] = toBin[x][3];
			}
		}

#if 1
		// print out image
		for (int i = 0; i<=h+1; i++)
		{
			for (int j = 0; j<=w*4+1; j++)
				printf("%d", arr[i][j]);
			printf("\n");
		}
#endif
		








	}





	return 0;
}