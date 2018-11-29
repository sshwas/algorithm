#include <cstdio>
#include <queue>
using namespace std;

#define MAXN		(100001)
#define MIN(a, b)	(((b)==-1) ? (a) : (((a) < (b)) ? (a) : (b)))

int DP[4][MAXN];

class node
{
public:
	int a, b, count;
	node(int x, int y, int count)
	{
		a = x;
		b = y;
		this->count = count;
	}
};

int main(void)
{
	int log = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 100001; j++)
			DP[i][j] = -1;

	int sa, sb, ta, tb;
	scanf("%d %d %d %d", &sa, &sb, &ta, &tb);
	if (!(ta == 0 || ta == sa || tb == 0 || tb == sb))
	{
		printf("-1");
		return 0;
	}
	queue<node> q;
	q.push(node(0, 0, 0));

	while (1)
	{
		log++;
		if (q.size() == 0)
			break;
		int type;
		node n = q.front();

		if (n.a == 0) type = 0;
		else if (n.a == sa) type = 1;
		else if (n.b == 0) type = 2;
		else type = 3;

		int temp;
		if (type < 2)
			temp = n.b;
		else 
			temp = n.a;
		if (DP[type][temp] == -1)
		{
			DP[type][temp] = n.count;
			if (DP[2][n.a] == -1)
				q.push(node(n.a, 0, n.count + 1));
			if (DP[3][n.a] == -1)
				q.push(node(n.a, sb, n.count + 1));
			if (DP[0][n.b] == -1)
				q.push(node(0, n.b, n.count + 1));
			if (DP[1][n.b] == -1)
				q.push(node(sa, n.b, n.count + 1));
			int tempa = n.a + n.b;
			int tempb;
			if (tempa > sa)
			{
				tempb = tempa - sa;
				tempa = sa;
			}
			else
				tempb = 0;
			q.push(node(tempa, tempb, n.count + 1));
			tempb = n.a + n.b;
			tempa;
			if (tempb > sb)
			{
				tempa = tempb - sb;
				tempb = sb;
			}
			else
				tempa = 0;
			q.push(node(tempa, tempb, n.count + 1));
			q.pop();
		}
		else
		{
			q.pop();
			continue;
		}
	}
	int count = 99999999;
	if (ta == 0)
		count = MIN(count, DP[0][tb]);
	if (ta == sa)
		count = MIN(count, DP[1][tb]);
	if (tb == 0)
		count = MIN(count, DP[2][ta]);
	if (tb == sb)
		count = MIN(count, DP[3][ta]);

	if (count == 99999999)
		printf("-1");
	else
		printf("%d", count);
}