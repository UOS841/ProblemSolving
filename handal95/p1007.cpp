#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

enum DIRECTION{
    POSITIVE = 0,
    NEGATIVE = 1,
};

typedef struct{
    int x;
    int y;
}vec;

int main(){
    int T;
    cin >> T;

    cout.setf(ios::fixed);
    cout.precision(12);
    while(T-- > 0){
        int N;
        cin >> N;
        vector<vec> vectors(N);

        for(int i = 0; i < N; i++){
            int x, y;
            cin >> x >> y;
            vectors[i] = {x, y};
        }

        vector<DIRECTION> v;
        for(int i = 0; i < N/2 ; i++){
            v.push_back(POSITIVE);
            v.push_back(NEGATIVE);
        }

        long long min_length = __LONG_LONG_MAX__;
        while(next_permutation(v.begin(), v.end())){
            vec vec_sum = {0, 0};
            for(int index = 0; index < N; index++){
                vec_sum.x += (v[index] == POSITIVE) ? vectors[index].x : -vectors[index].x;
                vec_sum.y += (v[index] == POSITIVE) ? vectors[index].y : -vectors[index].y;
            }
            long long result = pow(vec_sum.x, 2) + pow(vec_sum.y, 2);
            min_length = min(min_length, result);
        }

        double answer = sqrt((double)min_length);
        cout << answer << endl;
    }
}