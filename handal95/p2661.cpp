#include <iostream>
#include <vector>

using namespace std;

string backtracking(string str, char last, int N){
    if (str.length() == N){
        return str;
    }

    str = str + last;
    int cnt = str.length();
    for (int len = 1; len <= cnt / 2; len++){
        string substr_a = str.substr(cnt - len, len);
        string substr_b = str.substr(cnt - len * 2, len);

        if (substr_a == substr_b){
            return "";
        }
    }

    for (char next = '1'; next <= '3'; next++){
        string answer = backtracking(str, next, N);
        if(answer.length() == N){
            return answer;
        }
    }
    return "";
}

int main(){
    int N;
    cin >> N;
    string str = "";
    cout << backtracking(str, '1', N);
}