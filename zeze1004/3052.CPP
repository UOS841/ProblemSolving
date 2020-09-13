#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> v;
    int n=0;
    int remainder[42] ={0,};
    int sum=0;

    for(int i=0; i<10; i++) {
        cin >> n;
        //v.push_back(n%42);
        if(!remainder[n%42]++) {
            sum++;
        }
    }
    cout<<sum;


    return 0;
} 