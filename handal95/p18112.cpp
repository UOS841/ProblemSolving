#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int depth;
    int value;
};

int main(){
    string s_binary;
    string g_binary;
    getline(cin, s_binary);
    getline(cin, g_binary);

    int s_value = 0;
    int g_value = 0;
    for(int i = 0; i < s_binary.length(); i++){
        s_value *= 2;
        s_value += (s_binary[i] - '0'); 
    }
    for(int i = 0; i < g_binary.length(); i++){
        g_value *= 2;
        g_value += (g_binary[i] - '0'); 
    }

    Node node = { 0, s_value };
    queue<Node> q;
    q.push(node);

    int answer = 0;
    while (!q.empty() || answer > 1000){
        int depth = q.front().depth;
        int val = q.front().value;
        q.pop();

        if (val == g_value){
            answer = depth;
            break;
        }

        // add 1
    }

    cout << answer;
}