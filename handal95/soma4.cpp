#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

typedef vector<vector<int>> Graph;
map<string, int> m;
map<int, string> v;
Graph graph;

void dfs(int index, vector<string> answer){
    if(graph[index].size() == 0){
        for(int i = 0; i < answer.size(); i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    } else {
        for(int i = 0; i < graph[index].size(); i++){
            answer.push_back(v[graph[index][i]]);
            dfs(graph[index][i], answer);
            answer.pop_back();
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    string inputs;
    getline(cin, inputs);

    int count = 0;
    int index = 0;
    for(int i = 1; i < inputs.length(); i++){
        if(inputs[i] == ' '){
            m.insert({inputs.substr(index, i - index), count});
            v.insert({count, inputs.substr(index, i - index)});
            index = i + 1;
            count++;
        }
    }
    m.insert({inputs.substr(index, inputs.size() - index), count});
    v.insert({count, inputs.substr(index, inputs.size() - index)});

    int N;
    cin >> N;
    vector<bool> solo_skills(m.size(), true);
    graph.resize(m.size(), vector<int>());

    for(int i = 0; i < N; i++){
        string from, to;
        cin >> from >> to;

        graph[m[from]].push_back(m[to]);
        solo_skills[m[to]] = false;
    }


    for(int i = 0; i < m.size(); i++){
        vector<string> answer;
        if(solo_skills[i]){
            answer.push_back(v[i]);
            dfs(i, answer);
        }
    }
}