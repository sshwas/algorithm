// reference : ACM-ICPC 2011 World Finals C
#include <cstdio>

#define MAX_NUM		(203)

const int toBin[16][4] =
	{ { 0,0,0,0 },{ 0,0,0,1 },{ 0,0,1,0 },{ 0,0,1,1 },{ 0,1,0,0 },{ 0,1,0,1 },{ 0,1,1,0 },{ 0,1,1,1 },
	  { 1,0,0,0 },{ 1,0,0,1 },{ 1,0,1,0 },{ 1,0,1,1 },{ 1,1,0,0 },{ 1,1,0,1 },{ 1,1,1,0 },{ 1,1,1,1 } };
const char ancient[7] = "WAKJSD"; // index indicates the number of holes
int arr[MAX_NUM][MAX_NUM]; // input, arr[h][w*4] (0<h<=200, 0<w<=50, w should be changed to Binary)
int CharCnt[6];

void fill(int x, int y, int num)
{
    if (x == MAX_NUM || y == MAX_NUM)
        return;
    if (arr[x][y] == 1 || arr[x][y] == num)
        return;
    arr[x][y] = num;
    fill(x + 1, y, num);
    fill(x, y + 1, num);
}



int main()
{
	int h, w;
	while (scanf("%d %d", &h, &w))
	{
		if (!h && !w)
			break;

		// initialization with zero-padding
        for (int i = 0; i <= h + 1; i++)
        {
            arr[i][0] = 0;
            arr[i][w*4+1] = 0;
        }
        for (int i = 0; i <= w * 4 + 1; i++)
        {
            arr[0][i] = 0;
            arr[h+1][i] = 0;
        }

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

        // fill -1 instead of 0 in the background
        fill(0, 0, -1);
               
        // flood-fill
        for (int i = 1; i < MAX_NUM; i++)
        {
            for (int j = 1; j < MAX_NUM; j++)
            {
                if (arr[i][j] == 1)
                {

                }
            }
        }



#if 0
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