#include <cstdio>

int main()
{
	int tc;
	scanf("%d\n", &tc);
	while(tc--)
	{
		char str[202], s1[101], s2[101], temp;
		int i = 0;
		while ((temp = getchar()) != '\n') str[i++] = temp;
		str[i] = 0;
		char* pStr = str;
		char* pS1 = s1;
		char* pS2 = s2;

		int cnt1[128] = { 0, };
		int cnt2[128] = { 0, };
		while (*pStr != ' ')
			*pS1++ = *pStr, cnt1[*pStr++]++;
		*pS1 = 0, pStr++;
		while (*pStr != 0)
			*pS2++ = *pStr, cnt2[*pStr++]++;
		*pS2 = 0;
		bool same = true;
		for(int i = 0; i < 128; ++i)
		{
			if (cnt1[i] != cnt2[i])
			{
				same = false;
				break;
			}
		}
		printf("%s & %s %s\n", s1, s2, (same ? "are anagrams." : "are NOT anagrams."));
	}

	return 0;
}
