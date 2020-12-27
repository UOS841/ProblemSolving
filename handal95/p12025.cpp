#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long K;
    string str;

    cin >> str >> K;

    long long count = 0;
    for(int i = 0; i < str.length() ; i++){
        if(str[i]=='1' || str[i]=='6' || str[i] == '2' || str[i] == '7')
            count++;
    }   
    K = K - 1;

    long long comparison = pow(2, count);
    if ( K >= comparison || K < 0){
        cout << -1 << "\n";
    }else{
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '1' || str[i] == '6'){
                count--;
                long long comparison = pow(2, count);
                if( K >= comparison ){
                    K -= comparison;
                    str[i] = '6';
                }else{
                    str[i] = '1';
                }
            }else if(str[i] == '2' || str[i] == '7'){
                count--;
                long long comparison = pow(2, count);
                if( K >= comparison ){
                    K -= comparison;
                    str[i] = '7';
                }else{
                    str[i] = '2';
                }
            }
        }
        cout << str << "\n";
    }
}