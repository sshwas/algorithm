class Trie
{
public:
	Trie()
	{
		for (int i = 0; i < 26; i++)
			next[i] = 0;
	}

	void add(char* str)
	{
		if (*str != 0)
		{
			if (next[*str - 'a'] == 0)
				next[*str - 'a'] = new Trie();
			next[*str - 'a']->add(str + 1);
		}
	}

	Trie* get(char* str)
	{
		if (*str != 0)
		{
			if (next[*str - 'a'] != 0)
				return next[*str - 'a']->get(str + 1);
			return 0;
		}
		return this;
	}

private:
	Trie *next[26];
};

int main()
{
	return 0;
}