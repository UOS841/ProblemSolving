#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    vector<int> inputs(str.length());

    for(int i = 0; i < str.length(); i++){
        inputs[i] = str[i] - '0';
    }

    sort(inputs.begin(), inputs.end());
    for(int i = inputs.size() - 1; i >= 0; i--){
        cout << inputs[i];
    }
}