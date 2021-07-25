#include <iostream>
#include <vector>

using namespace std;

pair<bool, int> is_str_palindrome(string text)
{
	for (int i = 0, j = text.length() - 1; i < j; i++, j--)
	{
		if (text[i] != text[j])
		{
			return make_pair(false, i);
		}
	}
	return make_pair(true, 0);
}

bool is_possible_making_substr_palindrome(string text)
{
	// substring이 한 글자인 경우 true
	if (text.length() == 1)
	{
		return true;
	}

	bool erase_leftside = false, erase_rightside = false;

	// 왼쪽 문자를 지우는 경우
	if (text[1] == text[text.length() - 1])
	{
		string substring = text.substr(1);
		if (is_str_palindrome(substring).first == true)
		{
			erase_leftside = true;
		}
	}

	// 오른쪽 문자를 지우는 경우
	if (text[0] == text[text.length() - 2])
	{
		string substring = text.substr(0, text.length() - 1);
		if (is_str_palindrome(substring).first == true)
		{
			erase_rightside = true;
		}
	}

	return erase_leftside || erase_rightside;
}

int check_palindrome(string text)
{
	pair<bool, int> first_filter = is_str_palindrome(text);

	// text가 회문이라면 0 출력
	if (first_filter.first == true)
	{
		return 0;
	}
	else
	{
		int index = first_filter.second;
		string substring = text.substr(index, text.length() - 2 * index);
		bool second_filter = is_possible_making_substr_palindrome(substring);

		// text가 유사회문이라면 1 출력
		if (second_filter == true)
		{
			return 1;
		}
		// 그 외의 경우 2 출력
		else
		{
			return 2;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	vector<string> text(T);
	for (int t = 0; t < T; t++)
	{
		cin >> text[t];
	}

	for (int t = 0; t < T; t++)
	{
		cout << check_palindrome(text[t]) << endl;
	}

	return 0;
}