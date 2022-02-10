#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> convert_score_to_board(string score_str)
{
	vector<vector<int>> board(13, vector<int>(2, 0));
	int frame = 1;
	int phase = 0;

	int i = 0;
	while (i < score_str.size())
	{
		int phase_1, phase_2;

		// 해당 프레임에서 스트라이크를 친 경우
		if (score_str[i] == 'S')
		{
			// n프레임의 스트라이크 정보를 score[n - 1]에 기록
			// cf) 10프레임의 스트라이크 정보는 score[10], [11], [12]에 저장하도록 유도
			phase_1 = 10;
			phase_2 = 0;
		}
		// 10프레임에서 스페어를 통해 얻은 추가 기회의 점수가 스트라이크가 아닌 경우
		else if (i == score_str.size() - 1)
		{
			if (score_str[i] == '-')
			{
				phase_1 = 0;
			}
			else if (score_str[i] == 'P')
			{
				phase_1 = 10;
			}
			else
			{
				phase_1 = score_str[i] - '0';
			}
			phase_2 = 0;
		}
		// 해당 프레임에서 두 번 볼링공을 던진 경우
		else
		{
			// 첫 번째 드로우
			if (score_str[i] == '-')
			{
				phase_1 = 0;
			}
			else
			{
				phase_1 = score_str[i] - '0';
			}

			// 두 번째 드로우
			if (score_str[i + 1] == '-')
			{
				phase_2 = 0;
			}
			else if (score_str[i + 1] == 'P')
			{
				phase_2 = 10 - phase_1;
			}
			else
			{
				phase_2 = score_str[i + 1] - '0';
			}

			i++;
		}

		board[frame][0] = phase_1;
		board[frame][1] = phase_2;
		frame++;
		i++;
	}

	return board;
}


void print_board(vector<vector<int>> board)
{
	for (int i = 0; i < board.size(); i++)
	{
		cout << board[i][0] << " " << board[i][1] << endl;
	}
}


int calc_score(vector<vector<int>> board)
{
	vector<int> frame_score(11, 0);
	int result = 0;

	for (int frame = 1; frame < 13; frame++)
	{
		int phase_1 = board[frame][0];
		int phase_2 = board[frame][1];

		// 10프레임
		if (frame >= 10)
		{
			frame_score[10] += (phase_1 + phase_2);
		}
		else
		{
			frame_score[frame] += (phase_1 + phase_2);

			if (frame_score[frame] == 10)
			{
				// 스트라이크
				if (phase_1 == 10)
				{
					int bonus_1, bonus_2;

					// 그 다음 프레임에서도 스트라이크를 친 경우
					bonus_1 = board[frame + 1][0];
					if (bonus_1 == 10)
					{
						// 다다음 프레임의 점수가 보너스
						bonus_2 = board[frame + 2][0];
					}
					else
					{
						bonus_2 = board[frame + 1][1];
					}

					frame_score[frame] += (bonus_1 + bonus_2);
				}
				// 스페어
				else
				{
					int bonus = board[frame + 1][0];
					frame_score[frame] += bonus;
				}
			}
		}
	}

	/*
	for (int i = 1; i <= 10; i++)
	{
		cout << frame_score[i] << " ";
	}
	cout << endl;
	*/
	for (int i = 1; i <= 10; i++)
	{
		result += frame_score[i];
		//cout << result << " ";
	}

	return result;
}


int main()
{
	string score_str;
	cin >> score_str;

	print_board(convert_score_to_board(score_str));

	cout << calc_score(convert_score_to_board(score_str));

	return 0;
}