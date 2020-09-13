#include <iostream>
#include <list>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str; // 초기 string
	int	M;      // # of operator 
	cin >> str;
	cin >> M;

	list<char> list(str.begin(), str.end());
	auto cursor = list.end();

	for (int i = 0; i < M; i++) {
		char op;
		cin >> op;
		switch (op){
			case 'L': {
				if (cursor != list.begin()) {
					cursor--;
				}
				break;
			}
			case 'D': {
				if (cursor != list.end()) {
					cursor++;
				}
				break;
			}
			case 'B': {
				if (cursor != list.begin()) {
					cursor--;
					cursor = list.erase(cursor);
				}
				break;
			}
			case 'P': {
				char x;
				cin >> x;
				list.insert(cursor, x);
				break;
			}
		}
	}
	for (auto& x : list)
		cout << x;

	return 0;
}