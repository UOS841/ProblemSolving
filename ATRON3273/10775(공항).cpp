#include <iostream>
#include <vector>

using namespace std;

int gate[100001];

int find(int n)
{
	if (gate[n] == n)
	{
		return n;
	}
	else
	{
		return gate[n] = find(gate[n]);
	}
}

void merge(int a, int b)		// a >= b
{
	a = find(a);
	b = find(b);

	// cout << "gate[" << a << "] = " << b << endl;

	gate[a] = b;
}

int main()
{
	int G, P, max_plane = 0;
	cin >> G >> P;

	vector<int> plane(P);

	for (int i = 1; i <= G; i++)
	{
		gate[i] = i;
	}

	for (int i = 0; i < P; i++)
	{
		cin >> plane[i];
	}

	for (int i = 0; i < P; i++)
	{
		//cout << "plane " << i << endl;
		if (find(plane[i]) == 0)
		{
			//cout << "break\n";
			break;
		}
		else
		{
			/*
			cout << "before" << endl;
			for (int j = 1; j <= G; j++)
			{
				cout << gate[j] << " ";
			}
			cout << endl;
			*/
			max_plane++;
			merge(find(plane[i]), find(plane[i]) - 1);
			/*
			cout << "after" << endl;
			for (int j = 1; j <= G; j++)
			{
				cout << gate[j] << " ";
			}
			cout << endl;
			*/
		}
	}

	cout << max_plane;

	return 0;
}