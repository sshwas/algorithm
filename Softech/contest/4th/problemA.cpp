#include <cstdio>
#include <vector>
#include <queue>

#define MAX(a, b)	((a) > (b) ? (a) : (b))
using namespace std;

const int MAXN = 100001, inf = 987654321;
vector<pair<int, int>> ed[MAXN];
int pre[MAXN], dist[MAXN];
queue<int> q;
bool inQ[MAXN];

int main(void)
{
	int nRooms, s, e;
	scanf("%d %d %d", &nRooms, &s, &e);
	for (int i = 1; i < nRooms; i++) // # of edges = nRooms - 1
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		ed[u].push_back({ v, w });
		ed[v].push_back({ u, w });
	}
	for (int i = 1; i <= nRooms; i++)
		dist[i] = inf, inQ[i] = false;

	int max = 0;
	dist[s] = 0;
	q.push(s), inQ[s] = true;
	while (!q.empty())
	{
		int a = q.front(); q.pop();
		inQ[a] = false;
		for (auto it : ed[a])
		{
			if (dist[it.first] > (dist[a] + it.second))
			{
				dist[it.first] = dist[a] + it.second;
				pre[it.first] = a;

				if (it.first == e)
					break;
				if (!inQ[it.first])
				{
					q.push(it.first);
					inQ[it.first] = true;
				}
			}
		}
	}
	for (int i = e; i != s; i = pre[i])
		max = MAX(max, dist[i] - dist[pre[i]]);

	printf("%d", (dist[e] ? (dist[e] - max) : 0));
	return 0;
}