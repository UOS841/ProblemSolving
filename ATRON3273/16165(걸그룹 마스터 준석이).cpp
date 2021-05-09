#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	// 데이터 입력
	map<string, string> group;
	map<string, string>::iterator iter;
	for (int i = 0; i < N; i++)
	{
		string group_name;
		int member_num;
		cin >> group_name;
		cin >> member_num;
		
		for (int j = 0; j < member_num; j++)
		{
			string idol_name;
			cin >> idol_name;
			group.insert({ idol_name, group_name });
		}
	}

	// 퀴즈
	for (int quiz = 0; quiz < M; quiz++)
	{
		string question_name;
		cin >> question_name;
		int question;
		cin >> question;

		// 팀 이름으로 멤버 구하기
		if (question == 0)
		{
			for (auto iter = group.begin(); iter != group.end(); iter++)
			{
				if (iter->second == question_name)
				{
					cout << iter->first << endl;
				}
			}
		}
		// 멤버원 이름으로 팀 이름 구하기
		else
		{
			iter = group.find(question_name);

			if (iter != group.end())
			{
				cout << iter->second << endl;
			}
		}
	}

	return 0;
}