#include <iostream>
#include <vector>

using namespace std;

typedef struct dot
{
	long long x;
	long long y;
} dot;

double ccw(dot d1, dot d2, dot d3)
{
	return (d1.x * d2.y + d2.x * d3.y + d3.x * d1.y) - (d1.y * d2.x + d2.y * d3.x + d3.y * d1.x);
}

int main()
{
	int N;
	double result = 0;
	cin >> N;

	vector<dot> D(N);

	for (int i = 0; i < N; i++)
	{
		cin >> D[i].x >> D[i].y;
	}

	for (int i = 1; i < N - 1; i++)
	{
		result += ccw(D[0], D[i], D[i + 1]);
	}
	
	cout.setf(ios::fixed);
	cout.precision(1);
	cout << abs(result) / 2.0;
	return 0;
}