#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int main() {
    vector<int> v;
    int num,order,max;
    
    for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
    max = v[0];
    for (int j = 0; j < n; j++) {
        if (max < v[j]) {
            max = v[j];
            }
        }
    cout << max << '\n' << j;
}
*/

using namespace std;
int main()
{
    int A[100];
    int MAX=0;
    int number = 0;
    for (int i = 1; i <= 9; i++)
    {
        cin >> A[i];
        if (MAX < A[i]) 
        {
            MAX = A[i];
            number = i;
        }
    }
    cout << MAX << endl << number;
}