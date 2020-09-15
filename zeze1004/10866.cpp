// 참고: 출처: https://jaimemin.tistory.com/837 [꾸준함]
/*
 덱은 큐, 스택의 확장형
 앞 뒤로 입력,출력 가능
*/
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void) {
        // 건호 교수님이 말한 빨리 출력하기
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // ------------------------------
        int N;
        // 명령의 수
        cin >> N;   

        deque<int> deq;
        // 입력받을 수
        int num;
        for (int i = 0; i < N; i++) {
                // 명령어
                string str;
                cin >> str;
                 if (str == "push_back") {
                    cin >> num;
                    // push_back: 정수 ㅇㅇ를 덱의 뒤에 넣는다.
                    deq.push_back(num);
                }
                else if (str == "push_front") {
                    cin >> num;
                    // push_back: 정수 ㅇㅇ를 덱의 앞에 넣는다.
                    deq.push_front(num);
                }
                else if (str == "pop_front") {
                        if (deq.empty()) {
                            cout << -1 << "\n";}
                         else {
                                cout << deq.front() << "\n";
                                deq.pop_front();
                        }
                 }
                 else if (str == "pop_back") {
                    if (deq.empty()) {
                        cout << -1 << "\n";
                    }
                    else {                        
                        cout << deq.back() << "\n";
                        deq.pop_back();
                    }
                }
                else if (str == "size") {
                    cout << deq.size() << "\n";

                }
                else if (str == "empty") {
                 
                         if (deq.empty()) {
                            cout << 1 << "\n";
                         }
                         else {
                            cout << 0 << "\n";
                        }
                }
                 else if (str == "front") {
                    if (deq.empty()) {
                        cout << -1 << "\n";
                    }
                    else {
                        cout << deq.front() << "\n";
                    }
                 }
                 else if (str == "back")
                 {
                    if (deq.empty()) {
                        cout << -1 << "\n";
                    }
                    else {
                        cout << deq.back() << "\n"; 
                    }       
            }   
    }
    return 0;

}


