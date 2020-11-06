#include <iostream>
#include <vector>

using namespace std;

typedef struct area
{
	int x;
	int y;
	int r;
} area;

area enemy[3000];		// 여기에 각 진영의 정보 저장
int aliance[3000];		// 여기에 각 진영의 동맹관계에 있는 우두머리 진영의 정보 저장

// 동맹관계 탐색(find parent node)
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

// 동맹관계 합병
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

	// 테스트 케이스만큼 반복
	for (int test = 0; test < T; test++)
	{
		// 진영 갯수 입력
		int N, num_alliance;
		cin >> N;

		// 총 동맹 갯수 연산을 위한 num_alliance 변수 초기화
		num_alliance = N;

		// 진영 갯수만큼 입력 반복
		for (int num_enemy = 0; num_enemy < N; num_enemy++)
		{
			cin >> enemy[num_enemy].x >> enemy[num_enemy].y >> enemy[num_enemy].r;
			aliance[num_enemy] = num_enemy;
		}

		// 모든 가능한 조합을 비교
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				// 진영 i, j가 같은 동맹관계라면 무시
				if (find(i) == find(j))
				{
					continue;
				}

				// 각 진영 간 거리 계산
				int x = enemy[i].x - enemy[j].x;
				int y = enemy[i].y - enemy[j].y;
				int r = enemy[i].r + enemy[j].r;
				int square_distance = x * x + y * y;

				// 만약 각 진영 중심 간 거리가 각 진영의 범위의 합보다 작거나 같으면
				// 서로의 진영 범위가 겹치거나 스치므로 동맹관계
				if (square_distance <= r * r)
				{
					merge(i, j);
					num_alliance--;			// 두 팀이 동맹을 맺었으므로 총 동맹의 갯수 하나 감소
				}
			}
		}
		cout << num_alliance << endl;
	}
	return 0;
}