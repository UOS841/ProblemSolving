#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// VLR
string preorder(vector<vector<int>> tree)
{
	stack<int> s;
	string answer = "";

	s.push(0);
	while (!s.empty())
	{
		int cur_num = s.top();
		int cur_num_lc = tree[cur_num][0];
		int cur_num_rc = tree[cur_num][1];

		answer = answer + (char)(cur_num + 65);
		s.pop();

		// 오른쪽 자식 먼저 stack에 삽입
		if (cur_num_rc >= 0)
		{
			s.push(cur_num_rc);
		}
		// 그 후 왼쪽 자식 stack에 삽입
		if (cur_num_lc >= 0)
		{
			s.push(cur_num_lc);
		}
	}

	return answer;
}

// LVR
string inorder(vector<vector<int>> tree)
{
	vector<bool> visited(tree.size(), false);
	stack<int> s;
	string answer = "";

	s.push(0);
	visited[0] = true;
	while (!s.empty())
	{
		int cur_num = s.top();
		int cur_num_lc = tree[cur_num][0];
		int cur_num_rc = tree[cur_num][1];

		// 왼쪽 자식이 있는 경우 stack에 삽입
		if (cur_num_lc >= 0 && visited[cur_num_lc] == false)
		{
			visited[cur_num_lc] = true;
			s.push(cur_num_lc);
		}
		// 오른쪽 자식이 있거나 자식이 없는 경우
		else
		{
			// 현재 노드는 일단 pop
			answer = answer + (char)(cur_num + 65);
			s.pop();

			// 오른쪽 자식이 있는 경우 stack에 삽입
			if (cur_num_rc >= 0 && visited[cur_num_rc] == false)
			{
				visited[cur_num_rc] = true;
				s.push(cur_num_rc);
			}
		}
	}

	return answer;
}

// LRV
string postorder(vector<vector<int>> tree)
{
	vector<bool> visited(tree.size(), false);
	stack<int> s;
	string answer = "";

	s.push(0);
	visited[0] = true;
	while (!s.empty())
	{
		int cur_num = s.top();
		int cur_num_lc = tree[cur_num][0];
		int cur_num_rc = tree[cur_num][1];

		// 자식이 없는 노드는 pop
		if ((!(cur_num_lc >= 0 && visited[cur_num_lc] == false) && !(cur_num_rc >= 0 && visited[cur_num_rc] == false)))
		{
			answer = answer + (char)(cur_num + 65);
			s.pop();
		}
		// 자식이 있는 경우
		else
		{
			// 오른쪽 자식이 있다면 stack에 삽입
			if (cur_num_rc >= 0 && visited[cur_num_rc] == false)
			{
				visited[cur_num_rc] = true;
				s.push(cur_num_rc);
			}
			// 왼쪽 자식이 있다면 stack에 삽입
			if (cur_num_lc >= 0 && visited[cur_num_lc] == false)
			{
				visited[cur_num_lc] = true;
				s.push(cur_num_lc);
			}
		}
	}

	return answer;
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> tree(N);
	for (int i = 0; i < N; i++)
	{
		char parent, left_child, right_child;
		cin >> parent >> left_child >> right_child;

		int parent_num = (int)parent - 65;
		int left_child_num = (int)left_child - 65;
		int right_child_num = (int)right_child - 65;

		tree[parent_num].push_back(left_child_num);
		tree[parent_num].push_back(right_child_num);
	}

	cout << preorder(tree) << endl;
	cout << inorder(tree) << endl;
	cout << postorder(tree) << endl;

	return 0;
}