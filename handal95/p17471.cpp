#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10000

typedef vector<vector<int>> Graph;
typedef vector<int> Group;
enum GROUP{
    GROUP_A = 0,
    GROUP_B = 1,
};

Group check_visit(Group visited, Group selected, int team_leader);
bool is_connected(Group selected, int count);
void select(Group selected, int index, int count);

Graph graph;
Group popularity;
int answer = MAX;

int main(){
    int N;
    cin >> N;
    popularity.resize(N+1);
    graph.resize(N+1);
    Group selected(N+1);

    // Input popularity
    for(int i = 1 ; i <= N; i++){
        cin >> popularity[i];
    }

    // Input graph info
    int connected;
    for(int i = 1; i <= N; i++){
        cin >> connected;
        for(int node, j = 0; j < connected; j++){
            cin >> node;
            graph[i].push_back(node);
        }
    }

    // run
    select(selected, 1, 0);

    if(answer==MAX){
        answer = -1;
    }
    cout << answer;
}

void select(Group selected, int index, int count){
    if(index == selected.size()){
        if(is_connected(selected, count)){
            int val = 0;
            for(int i = 1 ; i < selected.size(); i++){
                if(selected[i] == GROUP_A){
                    val += popularity[i];
                }else{
                    val -= popularity[i];
                }
            }
            answer = min(answer, abs(val));
        }
        return;
    }

    selected[index] = GROUP_A;
    select(selected, index+1, count+1);

    selected[index] = GROUP_B;
    select(selected, index+1, count);
}

bool is_connected(Group selected, int count){
    // Break points
    if(count == 0 || count == selected.size() - 1){
        return false;
    }

    Group visited(selected.size(), false);
    // Group A check
    int team_a = 0;
    int team_b = 0;
    for(int i = 1; i <selected.size(); i++){
        (selected[i] == GROUP_A) ? team_a = i : team_b = i;
        
        if(team_a * team_b > 0)
            break;
    }

    // Team A
    visited = check_visit(visited, selected, team_a);
    // Team B
    visited = check_visit(visited, selected, team_b);

    for(int i = 1 ; i < visited.size(); i++ ){
        if(!visited[i])
            return false;
    }
    return true;
}

Group check_visit(Group visited, Group selected, int team_leader){
    queue<int> q;
    q.push(team_leader);
    visited[team_leader] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if(!visited[next] && selected[cur] == selected[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return visited;
}