#include <iostream>

using namespace std;

int main()
{
	unsigned long long k;

	string messed_password;
	string real_password = "";

	cin >> messed_password;
	cin >> k;
	k--;

	for (int i = messed_password.size() - 1; i >= 0; i--)
	{
		if (messed_password[i] == '1' || messed_password[i] == '6')
		{
			if (k % 2 == 0)
			{
				real_password = '1' + real_password;
			}
			else
			{
				real_password = '6' + real_password;
			}
			k >>= 1;
		}
		else if (messed_password[i] == '2' || messed_password[i] == '7')
		{
			if (k % 2 == 0)
			{
				real_password = '2' + real_password;
			}
			else
			{
				real_password = '7' + real_password;
			}
			k >>= 1;
		}
		else
		{
			real_password = messed_password[i] + real_password;
		}
	}
	if (k == 0)
	{
		cout << real_password;
	}
	else
	{
		cout << -1;
	}
	
	return 0;
}