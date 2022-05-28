#include <cstdio>

int main()
{
	int a, b, gcd, lcm, x, y;
	scanf("%d %d", &a, &b);
	x = a, y = b;

	int mod;
	while (b)
	{
		mod = a % b;
		a = b;
		b = mod;
	}
	gcd = a;
	lcm = x * y / gcd;

	printf("%d\n%d\n", gcd, lcm);

	return 0;
}