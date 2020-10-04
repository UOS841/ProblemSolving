#include <iostream>
#include <string>
#include <vector>


using namespace std;


vector<int> get_fail(string str) {
	int len = str.length();
	vector<int> fail(len, 0);

	for (int i = 1, j = 0; i < len; i++) {
		while (j > 0 && str[i] != str[j]) {
			j = fail[j - 1];
		}
		if (str[i] == str[j]) {
			fail[i] = ++j;
		}
	}
	return fail;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true) {
		string str;
		getline(cin, str);
		if (str == ".") 
			break;


		int len = str.length();
		vector<int> fail = get_fail(str);

		int check = fail[len - 1];
		bool flag = check % (len - check) != 0;
		cout << (flag ? 1 : (len / (len - fail[len - 1]))) << "\n";
	}
}
