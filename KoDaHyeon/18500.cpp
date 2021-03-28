#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> cave;
int R, C, N; //행, 열, 막대던진 횟수

vector<pair<int,int>> findFlying(int startR, int startC) //startR, startC에서 bfs시작해서 클러스터 찾기
{
  vector<pair<int,int>> cluster;
  vector<vector<int>> visited(startR+1, vector<int>(C, 0));
  queue<pair<int,int>> q;

  q.push(make_pair(startR,startC));
  visited[startR][startC] = 1;

  while(!q.empty()){
    int nowR = q.front().first;
    int nowC = q.front().second;
    cluster.emplace_back(make_pair(nowR,nowC));
    if(cave[startR+1][nowC]=='x'){ //r+1행의 미네랄과 연결되어있으면
      cluster.clear();
      break;
    }
    q.pop();
    //r,c+1
    if(nowC+1<C){
      if(visited[nowR][nowC+1]==0){ //방문한적 없으면
        q.push(make_pair(nowR,nowC+1));
        visited[nowR][nowC+1] = 1;
      }
    }
    //r,c-1
    if(nowC-1>=0){
      if(visited[nowR][nowC-1]==0){
        q.push(make_pair(nowR,nowC-1));
        visited[nowR][nowC-1] = 1;
      }
    }
    //r-1,c
    if(nowR-1>=0){
      if(visited[nowR-1][nowC]==0){
        q.push(make_pair(nowR-1,nowC));
        visited[nowR-1][nowC] = 1;
      }
    }
    //r+1,c
    if(nowR+1<=startR){
      if(visited[nowR+1][nowC]==0){
        q.push(make_pair(nowR+1,nowC));
        visited[nowR+1][nowC] = 1;
      }
    }
  }

  return cluster;
}

void sinkCluster(vector<pair<int,int>> cluster) //공중에 떠있는 클러스터를 가라앉히기
{
  
}


int main()
{
  int h; //막대던진 높이

  cin >> R >> C;
  cave.resize(R, vector<char>(C));
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      cin >> cave[i][j];
    }
  }

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> h; //막대던진 높이
    int r = R-h;
    if(i%2==0){ //2, 4, 6..번째
      for(int c=C-1; c>=0; c--){
        if(cave[r][c]=='x'){
          break;
        }
      }
    }
    else{ //1, 3, 5..번째
      for(int c=0; c<C; c++){
        if(cave[r][c]=='x'){
          cave[r][c] = '.';
          //1)오른쪽에 대한 클러스터 찾기. 이 클러스터가 공중에 떠있는지 찾기.
          vector<pair<int,int>> cluster = findFlying(r,c+1);
          if(cluster.size() != 0){ //공중에 떠있는 클러스터면
            sinkCluster(cluster);
          }
          //2)위에 대한 클러스터 찾기(앞에서 위 타일을 포함하면 생략). 이 클러스터가 공중에 떠있는지 찾기.
          //공중에 떠있는지 찾기 = r+1행 타일과 연결되지 않은 클러스터면 따로 저장해서 반환(pair형 1차원 벡터)(안떠있으면 벡터길이 0)
          //3)그 클러스터의 모든 타일들을 한칸씩 아래로 내리면서, 맨아래 칸이 바닥에 닿거나 어떤 칸이 다른 클러스터와 수직으로 닿으면 stop
          break;
        }
      }
    }
  }
}