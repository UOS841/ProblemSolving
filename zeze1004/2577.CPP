#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> v;
    int arr[10] = {0};
    for (int i =0; i<3; i++) {
        cin >> n;
        v.push_back(n);
    }
    int all = v[0] * v[1] * v[2];
    while(all != 0) {
        arr[all%10] += 1;   //0, 0, 3, 7, 3, 0, 7, 1
        all /= 10;
    }
    for(int j=0;j<10;j++){
        cout<<arr[j]<<'\n';
    }
    return 0;
}