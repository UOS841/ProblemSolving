#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Sdoku;
Sdoku sdoku(9, vector<int>(9));


void back_tracking(int solved);
bool flag = false;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int solved = 0;
    for (int row = 0; row < 9; row++){
        string str;
        cin >> str;
        for (int col = 0; col < 9; col++){
            int box = (row / 3) * 3 + (col / 3);
            int num = str[col] - '0';
            sdoku[row][col] = num;

            if (sdoku[row][col] > 0){
                solved++;
            }
        }
    }

	back_tracking(0);
    return 0;
}

void back_tracking(int solved) {
	if (flag) return;

	if (solved == 81) {
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++)
				cout << sdoku[row][col];
			cout << '\n';
		}
		flag = true;
		return;
	}

	int row = solved / 9;
	int col = solved % 9;
	if (sdoku[row][col] > 0) {
        back_tracking(solved + 1);
    } else {
		for (int num = 1; num <= 9; num++) {
			bool is_candidate = true;

            // Row Search
			for (int c = 0; c < 9 && is_candidate; c++) {
				if (sdoku[row][c] == num){
					is_candidate = false;
				}
			}

            // Col Search
			for (int r = 0; r < 9 && is_candidate; r++) {
				if (sdoku[r][col] == num) {
					is_candidate = false;
				}
			}

            // Box Search
            int rbox = (row / 3) * 3;
            int cbox = (col / 3) * 3;
			for (int r = rbox; r < rbox + 3 && is_candidate; r++) {
				for (int c = cbox; c < cbox + 3 && is_candidate; c++) {
					if (sdoku[r][c] == num) {
						is_candidate = false;
					}
				}
			}

			if (is_candidate) {
				sdoku[row][col] = num;
				back_tracking(solved + 1);
				sdoku[row][col] = 0;
			}
		}
	}
}
