#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string word;
	cin >> word;

	int size = word.size();
	vector<string> arr(size);

	for (int i = 0; i < size; i++)
	{
		arr[i] = word.substr(i);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\n";
	}
}