#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	long long min, max;
	cin >> min >> max;

	long long scope = max - min + 1;
	vector<bool> sieve(scope, false);

    long long answer = scope;
    for(long long i = 2; i * i <= max; i++){
		long long multiflier = min / (i * i);
		if (min % (i * i) != 0){
            multiflier += 1;
        }

        for(;multiflier * (i * i) <= max; multiflier++) {
			if (sieve[multiflier * (i * i) - min] == false) {
				sieve[multiflier * (i * i) - min] = true;
				answer--;
			}
		}
	}

	cout << answer;
}