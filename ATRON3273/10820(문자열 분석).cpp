#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N = 100;
	while (N > 0)
	{
		int upper = 0, lower = 0, space = 0, number = 0;
		string s;
		getline(cin, s);

		if (s.length() == 0)
		{
			break;
		}

		for (int i = 0; i < s.size(); i++)
		{
			if ((int)s[i] == 32)
			{
				space++;
			}
			else if ((int)s[i] >= 48 && (int)s[i] <= 57)
			{
				number++;
			}
			else if ((int)s[i] >= 65 && (int)s[i] <= 90)
			{
				upper++;
			}
			else if ((int)s[i] >= 97 && (int)s[i] <= 122)
			{
				lower++;
			}
		}

		cout << lower << " " << upper << " " << number << " " << space << "\n";
		N--;
	}
}