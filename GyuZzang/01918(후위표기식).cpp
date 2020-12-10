#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

int get_weight(char i) {
	switch (i){
	case '+':
	case '-':
		return 1;
	case '/':
	case '*':
		return 2;
	default: return 0;
	}
}

int main() {
	char input[101];
	stack<char> st;
	cin >> input;
	
	for (int i = 0;i<strlen(input);i++) {
		char now = input[i];
		if (now >= 65 && now <= 90) cout << now;
		else if (now == ')')
		{
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			if (st.empty() || now =='(' || get_weight(st.top()) < get_weight(now)) {
				st.push(now);
				//cout << 'push';
			}
			else {
				while (!st.empty() && (get_weight(st.top()) >= get_weight(now))) {
					if (get_weight(st.top())) cout << st.top();
					st.pop();
				}
				st.push(now);

					//cout << 'push';
			}

		}
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}

}