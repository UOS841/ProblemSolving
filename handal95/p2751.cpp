#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> array(N);
    for(int i = 0; i < N; i++){
        cin >> array[i];
    }

    sort(array.begin(), array.end());
    for(int i = 0; i < N; i++){
        cout << array[i] << "\n";
    }
}