#include <iostream>
#include <vector>

using namespace std;

string make_full_address(vector<string> group)
{
	string result;
	int zero_group_count = 8 - group.size();

	for (int i = 0; i < group.size(); i++)
	{
		// ::
		// 필요한 group 수만큼 0000:으로 채움
		if (group[i] == "colon")
		{
			while (zero_group_count >= 0)
			{
				result += "0000:";
				zero_group_count--;
			}
		}
		else
		{
			int zero_count = 4 - group[i].size();
			// group의 앞 부분을 0으로 채움
			while (zero_count > 0)
			{
				result += "0";
				zero_count--;
			}

			result += group[i];
			result += ":";
		}
	}

	// 맨 뒤의 :를 지우고 출력
	result = result.substr(0, result.size() - 1);
	return result;
}

vector<string> parse_address(string address)
{
	vector<string> group;

	int count = 0;
	bool is_before_char_colon = false;
	string parsing_group = "";

	// address를 탐색하여 파싱
	// 맨 뒤에 :를 붙여 맨 뒤 group도 파싱할 수 있도록 함
	for (auto c : (address + ':'))
	{
		if (c == ':')
		{
			// ::
			if (is_before_char_colon == true)
			{
				group.push_back("colon");
				is_before_char_colon = false;
			}
			// :
			else
			{
				// address 중간에 있는 :일 경우 파싱한 문자열을 추가
				// address의 맨 처음 글자가 :일 경우 true로 바꿔주기만 함
				if (parsing_group != "")
				{
					group.push_back(parsing_group);
					parsing_group = "";
				}
				is_before_char_colon = true;
			}
		}
		// 숫자, 문자
		else
		{
			parsing_group += c;
			is_before_char_colon = false;
		}
	}

	return group;
}

string IPv6(string address)
{
	vector<string> term = parse_address(address);
	return make_full_address(term);
}

int main()
{
	string address;
	cin >> address;

	cout << IPv6(address) << endl;

	return 0;
}