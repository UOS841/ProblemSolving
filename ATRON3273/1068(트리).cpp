#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> find_leaf_node(vector<int> tree_arr)
{
	set<int> leaf_node_set;

	for (int i = 0; i < tree_arr.size(); i++)
	{
		leaf_node_set.insert(i);
	}

	for (int i = 0; i < tree_arr.size(); i++)
	{
		leaf_node_set.erase(tree_arr[i]);
	}

	return leaf_node_set;
}

vector<pair<int, int>> sort_tree_array(vector<int> tree_arr)
{
	vector<pair<int, int>> sorted_tree(tree_arr.size());
	for (int i = 0; i < tree_arr.size(); i++)
	{
		sorted_tree[i].first = tree_arr[i];
		sorted_tree[i].second = i;
	}

	sort(sorted_tree.begin(), sorted_tree.end());
	return sorted_tree;
}

set<int> find_erase_node(vector<pair<int, int>> sorted_tree_arr, int erase_node)
{
	vector<bool> is_remain(sorted_tree_arr.size());
	set<int> erase_node_set;

	for (int i = 0; i < sorted_tree_arr.size(); i++)
	{
		int cur_node = sorted_tree_arr[i].second;
		int cur_node_parent = sorted_tree_arr[i].first;

		// 해당 노드가 지우는 노드인 경우
		if (cur_node == erase_node)
		{
			is_remain[cur_node] = false;
			erase_node_set.insert(cur_node);
		}
		// 해당 노드가 최상단 노드인 경우
		else if (cur_node_parent == -1)
		{
			is_remain[cur_node] = true;
		}
		// 해당 노드의 부모가 지우는 노드거나 지우는 노드의 자식인 경우
		else if (is_remain[cur_node_parent] == false)
		{
			is_remain[cur_node] = false;
			erase_node_set.insert(cur_node);
		}
		else
		{
			is_remain[cur_node] = true;
		}

		cout << cur_node << " : " << cur_node_parent << " " << is_remain[i] << endl;
	}

	return erase_node_set;
}

bool is_erase_node_has_sibling(vector<int> tree_arr, int erase_node)
{
	int count = 0;
	int parent_node_num = tree_arr[erase_node];

	for (int i = 0; i < tree_arr.size(); i++)
	{
		if (tree_arr[i] == parent_node_num)
		{
			count++;

			if (count > 1)
			{
				return true;
			}
		}
	}

	return false;
}

set<int> find_remain_node(set<int> leaf_node_set, set<int> erase_node_set, vector<int> tree_arr, int erase_node)
{
	set<int> remain_node_set = leaf_node_set;

	for (set<int>::iterator erase_iter = erase_node_set.begin(); erase_iter != erase_node_set.end(); erase_iter++)
	{
		set<int>::iterator leaf_iter = leaf_node_set.begin();
		while (leaf_iter != leaf_node_set.end())
		{
			if (*leaf_iter == *erase_iter)
			{
				remain_node_set.erase(*leaf_iter);
				break;
			}
			leaf_iter++;
		}
	}

	if (is_erase_node_has_sibling(tree_arr, erase_node) == false && tree_arr[erase_node] != -1)
	{
		remain_node_set.insert(tree_arr[erase_node]);
	}

	return remain_node_set;
}

int find_remain_node_num(set<int> remain_node_set)
{
	return remain_node_set.size();
}

int main()
{
	int N, erase_node;
	cin >> N;
	vector<int> tree(N);
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
	}
	cin >> erase_node;
	
	set<int> leaf_node_set = find_leaf_node(tree);
	set<int> erase_node_set = find_erase_node(sort_tree_array(tree), erase_node);
	set<int> remain_node_set = find_remain_node(leaf_node_set, erase_node_set, tree, erase_node);

	
	cout << "leaf : ";
	for (set<int>::iterator iter = leaf_node_set.begin(); iter != leaf_node_set.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "erase : ";
	for (set<int>::iterator iter = erase_node_set.begin(); iter != erase_node_set.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "remain : ";
	for (set<int>::iterator iter = remain_node_set.begin(); iter != remain_node_set.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	

	cout << find_remain_node_num(remain_node_set);
	return 0;
}