//실버 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> paper;
int minusOne = 0;
int zere = 0;
int one = 0;

void paperMethod(int row, int culrumn, int size){
    int i,j,matrix;
    // 첫 메소드 호출 시 matrix = paper[0][0]
    matrix = paper[row][culrumn];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // 첫 메소드 호출 시 paper[0][0]와 다른 원소가 있을 시
            if (paper[row+i][culrumn+j] != matrix) {
                // 종이를 1/3으로 분할
                size /= 3;
                // 분할 후 재귀
                paperMethod(row, culrumn, size);
                paperMethod(row, culrumn+size, size);
                paperMethod(row, culrumn+size*2, size);
                paperMethod(row+size, culrumn, size);
                paperMethod(row+size, culrumn+size, size);
                paperMethod(row+size, culrumn+size*2, size);
                paperMethod(row+size*2, culrumn, size);
                paperMethod(row+size*2, culrumn+size, size);
                paperMethod(row+size*2, culrumn+size*2, size);
                return;
            }
        }
    }
    // matrix(행렬 원소)값에 따라 구분
    switch (matrix)
    {
    case -1: minusOne++;
        break;
    case 0: zere++;
        break;
    case 1: one++;
        break;

    }


}    


int main() {
    int i,j, 
        N; // size of paper
	// get data: N
	cin >> N;
    // paper 행렬 크기
	paper.resize(N,vector<int>(N)); // <---- 몬 뜻?

	// get paper data
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			cin >> paper[i][j];
		}
	}
	
    // 분할정복 메소드
	paperMethod(0,0,N);

	// print out
	cout << minusOne << '\n'
	     << zere << '\n'
	     << one << '\n';

	return 0;

}