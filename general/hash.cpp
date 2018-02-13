#include <iostream>
#define PRIME_NUM	5381
#define MAX_NUM		99901
using namespace std;

typedef struct node {
	char str[11];
	struct node* prev;
} NODE;

NODE arr[MAX_NUM];
NODE *tHash[MAX_NUM];
int ptr;

NODE *myalloc()
{
	return &arr[ptr++];
}

int makeHash(char *str)
{
	char c;
	int key = PRIME_NUM;
	while ( (c=*str++) != '\0')
	{
		key = (((key << 5) + key + c) % MAX_NUM);
	}
	return key % MAX_NUM;
}

int main()
{
	ptr = 0;
	for (int i = 0; i < MAX_NUM; i++)
		tHash[i] = nullptr;

	char str1[11] = "helloworld";
	int key = makeHash(str1);
	NODE *p = myalloc();
	strncpy(p->str, str1, 11);
	p->prev = tHash[key];
	tHash[key] = p;

	char str2[11] = "helloworld";	
	for (NODE *k = tHash[makeHash(str2)]; k != nullptr; k = k->prev)
		if (!strncmp(str2, k->str, 11))
			cout << "Found : " << str2 << endl;
	
	return 0;
}