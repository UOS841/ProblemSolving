#include <iostream>

using namespace std;

int main()
{
	unsigned long long N;
	cin >> N;
	N %= 7;

	if (N == 0 || N == 2)
	{
		cout << "CY";
	}
	else
	{
		cout << "SK";
	}

	return 0;
}