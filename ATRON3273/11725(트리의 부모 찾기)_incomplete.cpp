#include <iostream>
#include <vector>

using namespace std;

vector<int> make_parent_info(vector<pair<int, int>>& list)
{
	//vector<vector<int>> child(list.size() + 2);
	vector<int> parent(list.size() + 2, -1);
	//child[0].push_back(1);
	parent[1] = 0;

	for (int i = 0; i < list.size(); i++)
	{
		int node1 = list[i].first;
		int node2 = list[i].second;
		int child_node, parent_node;
		
		if (parent[node1] == -1)
		{
			child_node = node1;
			parent_node = node2;
		}
		else
		{
			child_node = node2;
			parent_node = node1;
		}

		parent[child_node] = parent_node;
		//child[parent_node].push_back(child_node);
	}
	
	return parent;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> node_list(N - 1);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> node_list[i].first >> node_list[i].second;
	}

	vector<int> parent_info = make_parent_info(node_list);

	for (int i = 2; i <= N; i++)
	{
		cout << parent_info[i] << endl;
	}

	return 0;
}