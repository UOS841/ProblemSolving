#include <iostream>

using namespace std;

int main()
{
	string word;
	int alphabet[26];
	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = -1;
	}

	cin >> word;

	for (int i = 0; i < word.size(); i++)
	{
		if (alphabet[(int)word[i] - 97] != -1)
		{
			continue;
		}
		else
		{
			alphabet[(int)word[i] - 97] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << " ";
	}
}