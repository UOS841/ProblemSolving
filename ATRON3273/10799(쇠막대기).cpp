#include <iostream>
#include <string>

using namespace std;

int main()
{
	string stick;
	cin >> stick;

	int cur_stick = 0, num = 0;

	for (int i = 0; i < stick.size(); i++)
	{
		if (stick[i] == '(')
		{
			cur_stick++;
		}
		else if (stick[i] == ')')
		{
			cur_stick--;
			if (stick[i - 1] == '(')
			{
				num += cur_stick;
			}
			else
			{
				num += 1;
			}
		}
	}
	cout << num;

	return 0;
}