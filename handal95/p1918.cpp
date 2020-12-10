#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    string input;
    cin >> input;

    stack<char> s;
    int len = input.length();
    for(int i = 0 ; i < len; i++){
        char ch = input[i];
        if('A' <= ch && ch <= 'Z'){
            cout << ch;
        }else if(ch=='('){
            s.push(ch);
        }else if(ch == '*' || ch == '/'){
            while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                cout << s.top(); s.pop();
            }
            s.push(ch);
        }else if(ch == '+' || ch == '-'){
            while(!s.empty() && s.top() != '('){
                cout << s.top(); s.pop();
            }
            s.push(ch);
        }else if(ch == ')'){
            while(!s.empty() && s.top() != '('){
                cout << s.top(); s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty()){
        cout << s.top(); s.pop();
    }
}