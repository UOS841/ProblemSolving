#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int N, position = 1, amount_sub_zero = 0;
	cin >> N;

	while (N / position > 0)
	{
		for (int i = 0; i < 10; i++)
		{
			int tmp = 0;
			// 현재 탐색중인 숫자 i가 자릿수보다 더 클 경우
			if (N / position % 10 < i)
			{
				tmp += ((N / (position * 10)) * position);
			}
			// 현재 탐색중인 숫자 i와 자릿수가 같을 경우
			else if (N / position % 10 == i)
			{
				tmp += ((N / (position * 10)) * position);
				tmp += N % position + 1;
			}
			// 현재 탐색중인 숫자 i가 자릿수보다 더 작을 경우
			else
			{
				tmp += ((N / (position * 10) + 1) * position);
			}
			count[i] += tmp;
		}
		amount_sub_zero += position;
		position *= 10;
	}
	// 앞의 계산에선 페이지 숫자에 0이 모두 붙은 경우를 계산
	// 쓸모없는 0의 갯수는 N의 자릿수만큼 1을 붙인 숫자
	// (ex. 2563 -> 4자리 수로 쓸모없는 0의 갯수는 1111개)
	count[0] -= amount_sub_zero;

	for (int i = 0; i < 10; i++)
	{
		cout << count[i] << " ";
	}

	return 0;
}