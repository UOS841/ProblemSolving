#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct node
{
	int parent;
	vector<int> child;
} Node;

int main()
{
	int N;
	int num_D = 0, num_G = 0, max_child_num = 0;
	cin >> N;

	vector<Node> tree(N + 1);

	tree[0].parent = NULL;
	tree[0].child.push_back(1);
	tree[1].parent = 0;

	for (int i = 1; i < N; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u <= v)
		{
			tree[v].parent = u;
			tree[u].child.push_back(v);

			if (tree[u].child.size() > max_child_num)
			{
				max_child_num = tree[u].child.size();
			}
		}
		else
		{
			tree[u].parent = v;
			tree[u].child.push_back(u);

			if (tree[v].child.size() > max_child_num)
			{
				max_child_num = tree[v].child.size();
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << tree[i].parent << " <- " << i << " <- ";
		for (int j = 0; j < tree[i].child.size(); j++)
		{
			cout << tree[i].child[j] << " ";
		}
		cout << endl;
	}
	
	int combination
	for (int i = 1; i <= max_child_num; i++)
	{
		combination[i].resize(i + 1);
		for (int j = 1; j <= i + 1; j++)
		{
			if (j == 1 || j == max_child_num)
			{
				combination[i][j] = 1;
			}
			else
			{
				combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
			}
		}
	}

	for (int i = 1; i <= max_child_num; i++)
	{
		for (int j = 1; j <= i + 1; j++)
		{
			cout << combination[i][j] << " ";
		}
		cout << endl;
	}
	/*
	for (int i = 1; i <= N; i++)
	{
		if (tree[i].child.size() >= 3)
		{

		}
		/*
		// parent -> child edge 갯수 : 1
		if (tree[i].child.size() == 1)
		{
			// child의 child edge 갯수 : 1 | 'ㄷ'
			if (tree[tree[i].child[0]].child.size() == 1)
			{
				if (tree[tree[tree[i].child[0]].child[0]].child.size() == 1)
				{
					num_D += 1;
				}
				else
				{
					continue;
				}
			}
			// child의 child edge 갯수 : 2 | 'ㅈ'
			else if (tree[tree[i].child[0]].child.size() == 2)
			{
				num_G += 2;
			}
			else
			{
				continue;
			}
		}
		// parent -> child edge 갯수 : 2 | 'ㄷ'
		else if (tree[i].child.size() == 2)
		{
			if (tree[tree[i].child[0]].child.size() == 1 || tree[tree[i].child[1]].child.size() == 1)
			{
				num_D++;
			}
			else
			{
				continue;
			}
		}
		// parent -> child edge 갯수 : 3 | 'ㅈ'
		else if (tree[i].child.size() == 3)
		{
			num_G++;
		}
		else
		{
			continue;
		}
		
	}*/
	cout << num_D << " " << num_G << endl;
	return 0;
}