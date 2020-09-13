#include <iostream>
#include <string>


using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	while (getline(cin, str)) {
		int lower = 0;
		int upper = 0;
		int digit = 0;
		int space = 0;


        int len = str.length();
		for (int i = 0; i < len; i++) {
			char ch = str.at(i);
			if ('A' <= ch && ch <= 'z') {
				if (ch <= 'Z') {
					upper++;
				}
				else {
					lower++;
				}
			}
			else {
				if ('0' <= ch && ch <= '9') {
					digit++;
				}
				else {
					space++;
				}
			}
		}

		cout << lower << " " << upper << " ";
		cout << digit << " " << space << "\n";
	}

    return 0;
}