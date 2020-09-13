#include <iostream>

using namespace std;

int main()
{
	string word;
	int alphabet[26] = { 0 };
	cin >> word;

	for (int i = 0; i < word.size(); i++)
	{
		alphabet[(int)word[i] - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << " ";
	}
}