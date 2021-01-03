#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){
    int N;
    cin >> N;

    int baseint = 0;
    vector<int> numbers(10);
    for(int val = N, i = 0; val > 0; val /= 10, i++){
        int rest = val % 10;
        baseint += (rest) * (i * pow(10, i - 1));

        for(int j = 1; j < rest; j++)
            numbers[j] += (int)pow(10, i);

        numbers[rest] += N % (int)pow(10, i) + 1;
        if(rest == 0) {
            numbers[0] -= (pow(10, i));
        }
    }

    for(int i = 0; i < 10; i++){
        numbers[i] += baseint;
        cout << numbers[i] << " ";
    }

    vector<int> valid(10);
    for(int num = 1; num <= N; num++){
        int val = num;
        while(val > 0){
            valid[val%10]++;
            val /= 10;
        }
    }
    cout << endl << "valid" << endl;
    for(int i = 0; i < 10; i++){
        cout << valid[i] << " ";
    }
    cout << endl;

}