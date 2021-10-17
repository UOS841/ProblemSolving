#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<char> make_tree(vector<vector<char>> seed)
{
	vector<char> tree(100, '.');
	vector<int> index(26, 0);
	tree[1] = 'A';	// tree[idx of tree_head] = 'A'
	index[0] = 1;	// index['A' - 65] = idx of tree_head;

	for (int i = 0; i < seed.size(); i++)
	{
		// seed 데이터 불러옴
		char parent = seed[i][0];
		char left_child = seed[i][1];
		char right_child = seed[i][2];

		// ASCII 값 변환
		int parent_num = (int)parent - 65;
		int left_child_num = (int)left_child - 65;
		int right_child_num = (int)right_child - 65;

		// 현 index 배열을 통해 tree 인덱스 값 결정
		int parent_idx = index[parent_num];
		int left_child_idx = parent_idx * 2;
		int right_child_idx = parent_idx * 2 + 1;

		if (left_child_num >= 0)
		{
			tree[left_child_idx] = left_child;
			index[left_child_num] = left_child_idx;
		}

		if (right_child_num >= 0)
		{
			tree[right_child_idx] = right_child;
			index[right_child_num] = right_child_idx;
		}
	}

	return tree;
}

// VLR
string preorder(vector<char> tree)
{
	stack<int> s;
	string answer = "";

	s.push(1);
	while (!s.empty())
	{
		int cur_p = s.top();
		int cur_p_lc = cur_p * 2;
		int cur_p_rc = cur_p * 2 + 1;

		answer = answer + tree[cur_p];
		s.pop();

		// 오른쪽 자식 먼저 stack에 삽입
		if (cur_p_rc <= 26 && tree[cur_p_rc] != '.')
		{
			s.push(cur_p_rc);
		}
		// 그 후 왼쪽 자식 stack에 삽입
		if (cur_p_lc <= 26 && tree[cur_p_lc] != '.')
		{
			s.push(cur_p_lc);
		}
	}

	return answer;
}

// LVR
string inorder(vector<char> tree_source)
{
	stack<int> s;
	string answer = "";
	vector<char> tree = tree_source;

	s.push(1);
	while (!s.empty())
	{
		int cur_p = s.top();
		int cur_p_lc = cur_p * 2;
		int cur_p_rc = cur_p * 2 + 1;

		// 왼쪽 자식이 있는 경우 stack에 삽입
		if (cur_p_lc <= 26 && tree[cur_p_lc] != '.')
		{
			s.push(cur_p_lc);
		}
		// 오른쪽 자식이 있거나 자식이 없는 경우
		else
		{
			// 현재 노드는 일단 pop
			answer = answer + tree[cur_p];
			tree[cur_p] = '.';
			s.pop();

			// 오른쪽 자식이 있는 경우 stack에 삽입
			if (cur_p_rc <= 26 && tree[cur_p_rc] != '.')
			{
				s.push(cur_p_rc);
			}
		}
	}

	return answer;
}
// LRV
string postorder(vector<char> tree_source)
{
	stack<int> s;
	string answer = "";
	vector<char> tree = tree_source;

	s.push(1);
	while (!s.empty())
	{
		int cur_p = s.top();
		int cur_p_lc = cur_p * 2;
		int cur_p_rc = cur_p * 2 + 1;

		// 자식이 없는 노드는 pop
		if (tree[cur_p_lc] == '.' && tree[cur_p_rc] == '.')
		{
			answer = answer + tree[cur_p];
			tree[cur_p] = '.';
			s.pop();
		}
		// 자식이 있는 경우
		else
		{
			// 오른쪽 자식이 있다면 stack에 삽입
			if (cur_p_rc <= 26 && tree[cur_p_rc] != '.')
			{
				s.push(cur_p_rc);
			}
			// 왼쪽 자식이 있다면 stack에 삽입
			if (cur_p_lc <= 26 && tree[cur_p_lc] != '.')
			{
				s.push(cur_p_lc);
			}
		}
	}

	return answer;
}

int main()
{
	int N;
	cin >> N;

	vector<vector<char>> seed(N);
	for (int i = 0; i < N; i++)
	{
		char parent, left_child, right_child;
		cin >> parent >> left_child >> right_child;
		seed[i].push_back(parent);
		seed[i].push_back(left_child);
		seed[i].push_back(right_child);
	}

	vector<char> tree = make_tree(seed);

	cout << preorder(tree) << endl;
	cout << inorder(tree) << endl;
	cout << postorder(tree) << endl;

	return 0;
}