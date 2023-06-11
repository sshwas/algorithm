#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
using namespace std;

typedef struct pos
{
    int y;
    int x;
    int dist;
} POS;

const int MXN = 101;
bool map[MXN][MXN];
bool visit[MXN][MXN];
POS queue[MXN * MXN];
int head, tail;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%1d", &map[i][j]);

    head = tail = 0;
    queue[head++] = { 0, 0, 1 };
    visit[0][0] = true;

    while (head != tail)
    {
        POS front = queue[tail++];
        if (front.y == n - 1 && front.x == m - 1)
        {
            printf("%d\n", front.dist);
            break;
        }
        if (front.x < m - 1 && map[front.y][front.x + 1] && !visit[front.y][front.x + 1]) // east
            visit[front.y][front.x + 1] = true, queue[head++] = { front.y, front.x + 1, front.dist + 1 };
        if (front.x > 0 && map[front.y][front.x - 1] && !visit[front.y][front.x - 1]) // west
            visit[front.y][front.x - 1] = true, queue[head++] = { front.y, front.x - 1, front.dist + 1 };
        if (front.y > 0 && map[front.y - 1][front.x] && !visit[front.y - 1][front.x]) // north
            visit[front.y - 1][front.x] = true, queue[head++] = { front.y - 1, front.x, front.dist + 1 };
        if (front.y < n - 1 && map[front.y + 1][front.x] && !visit[front.y + 1][front.x]) // south
            visit[front.y + 1][front.x] = true, queue[head++] = { front.y + 1, front.x, front.dist + 1 };
    }
    return 0;
}
