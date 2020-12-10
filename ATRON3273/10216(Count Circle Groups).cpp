#include <iostream>
#include <vector>

using namespace std;

typedef struct area
{
	int x;
	int y;
	int r;
} area;

area enemy[3000];		// ���⿡ �� ������ ���� ����
int aliance[3000];		// ���⿡ �� ������ ���Ͱ��迡 �ִ� ��θӸ� ������ ���� ����

// ���Ͱ��� Ž��(find parent node)
int find(int x)
{
	if (x == aliance[x])
	{
		return x;
	}
	else
	{
		return aliance[x] = find(aliance[x]);
	}
}

// ���Ͱ��� �պ�
void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y)
	{
		aliance[y] = x;
	}
}

int main()
{
	int T;
	cin >> T;

	// �׽�Ʈ ���̽���ŭ �ݺ�
	for (int test = 0; test < T; test++)
	{
		// ���� ���� �Է�
		int N, num_alliance;
		cin >> N;

		// �� ���� ���� ������ ���� num_alliance ���� �ʱ�ȭ
		num_alliance = N;

		// ���� ������ŭ �Է� �ݺ�
		for (int num_enemy = 0; num_enemy < N; num_enemy++)
		{
			cin >> enemy[num_enemy].x >> enemy[num_enemy].y >> enemy[num_enemy].r;
			aliance[num_enemy] = num_enemy;
		}

		// ��� ������ ������ ��
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				// ���� i, j�� ���� ���Ͱ����� ����
				if (find(i) == find(j))
				{
					continue;
				}

				// �� ���� �� �Ÿ� ���
				int x = enemy[i].x - enemy[j].x;
				int y = enemy[i].y - enemy[j].y;
				int r = enemy[i].r + enemy[j].r;
				int square_distance = x * x + y * y;

				// ���� �� ���� �߽� �� �Ÿ��� �� ������ ������ �պ��� �۰ų� ������
				// ������ ���� ������ ��ġ�ų� ��ġ�Ƿ� ���Ͱ���
				if (square_distance <= r * r)
				{
					merge(i, j);
					num_alliance--;			// �� ���� ������ �ξ����Ƿ� �� ������ ���� �ϳ� ����
				}
			}
		}
		cout << num_alliance << endl;
	}
	return 0;
}