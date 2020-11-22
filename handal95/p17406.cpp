#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> Array;
typedef pair<pair<int, int>, int> Rotation;
#define MAX 5000

int answer = MAX;
vector<Rotation> rotations;

void print_array(Array array){
    cout << " ===== " << endl;
    for(int r = 0; r < array.size(); r++){
        for(int c = 0 ; c < array[0].size(); c++){
            cout << array[r][c] << " ";
        }
        cout << endl;
    }
}

int row_sum(vector<int> row){
    int row_sum = 0;
    for(int i = 0 ; i < row.size(); i++){
        row_sum += row[i];
    }
    return row_sum;
}

int min_sum(Array array){
    int min_sum = MAX;
    for(int row = 0 ; row < array.size(); row++){
        int sum = row_sum(array[row]);
        cout << sum << endl;
        min_sum = min(min_sum, sum);
    }
    answer = min(answer, min_sum);
    return min_sum;
}

void rotate(Array array, Rotation rotation, int k){
    int pv_row = rotation.first.first;
    int pv_col = rotation.first.second;
    int range = rotation.second;

    vector<int> temp;
    while(range > 0){
        int LU_row = pv_row - range;
        int LU_col = pv_col - range;
        int RD_row = pv_row + range-1;
        int RD_col = pv_col + range-1;
        int iter = 2*range - 1;

        for(int i = 0; i < iter; i++){
            temp.push_back(array[LU_row][LU_col+i]);
        }

        for(int i = 0; i < iter; i++){
            array[LU_row][LU_col+i] = array[LU_row+i][RD_col];
        }

        for(int i = 0; i < iter; i++){
            array[LU_row+i][RD_col] = array[RD_row][RD_col-i];
        }

        for(int i = 0; i < iter; i++){
            array[RD_row][RD_col-i] = array[RD_row-i][LU_col];
        }

        for(int i = 0; i < iter; i++){
            array[RD_row-i][LU_col] = temp[i];
        }

        range--;
    }
    if(k==2){
        rotate(array, rotations[1], k-1);
    }
    if(k==1){
        min_sum(array);
    }
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    Array array(N, vector<int>(M));
    for(int r = 0; r < N; r++){
        for(int c = 0 ; c < M ; c++){
            cin >> array[r][c];
        }
    }

    int row, col, range;
    for(int k = 0; k < K ; k++){
        cin >> row >> col >> range;
        rotations.push_back(make_pair(make_pair(row, col), range));
    }

    rotate(array, rotations[0], K);
    cout << "answer" << answer << endl;
}