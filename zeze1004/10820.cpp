#include <iostream>
#include <string.h>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
       
    for(int i = 0; i < 100; i ++) {
        int smallChar = 0, largeChar = 0, num = 0, null = 0;
        string str;
        // getline: 문자열 받기 
        // n-1만 문자, n의 null 저장
        getline(cin, str);
        if (str.length() == 0)
            break;

        for(int j = 0; j<str.length(); j++) {        
            // isalpha(): 알파벳이 아니라면 리턴 0, 대문자 1, 소문자 2
            //if(isalpha(str[j]) == 2) 
            if(str[j] >= 'a' && str[j] <= 'z')
                smallChar++;   
            //else if(isalpha(str[j]) == 1)
            else if(str[j] >= 'A' && str[j] <= 'Z')
                largeChar++;
            
            // isdigit(): 숫자면 true, 아니면 false
            // if(isdigit(str[j]) == true)
            else if(str[j] >= '0' && str[j] <= '9')
                num++;
            else
                null++; 
        
            cout << smallChar << " " << largeChar << " " << num << " " << null << '\n';
        }
    }
    
    return 0;
}