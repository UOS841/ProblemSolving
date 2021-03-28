#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M; //행, 열
vector< vector<int> > box;

int bfs(int r, int c)
{
  vector< vector<int> > visited(N, vector<int>(M, 0));
  vector< vector<int> > level(N, vector<int>(M, 0));
  queue< pair<int,int> > q;
  q.push(make_pair(r,c));
  visited[r][c] = 1;

  while(!q.empty()){
    int nowR = q.front().first;
    int nowC = q.front().second;
    q.pop();
    if(box[nowR][nowC] == 1){
      //현재 level을 반환
      return level[nowR][nowC];
    }
    for(int i=nowR-1; i<=nowR+1; i++){
      for(int j=nowC-1; j<=nowC+1; j++){
        if(i<0 || j<0 || i>=N || j>=M) continue; //행렬 밖인 경우
        if(visited[i][j] != 0) continue; //이미 방문한 점인 경우 continue
        q.push(make_pair(i,j));
        visited[i][j] = 1;
        level[i][j] = level[nowR][nowC]+1;
      }
    }
  }
}

int main()
{
  int max_dis = 0; //안전거리 최댓값
  cin >> N >> M;
  box.resize(N, vector<int>(M));
  for(int r=0; r<N; r++){
    for(int c=0; c<M; c++){
      cin >> box[r][c];
    }
  }

  for(int r=0; r<N; r++){
    for(int c=0; c<M; c++){
      if(box[r][c]==0){
        //이 위치에 대해 bfs
        int now_dis = bfs(r,c);
        max_dis = (now_dis > max_dis)? now_dis : max_dis;
      }
    }
  }
  cout << max_dis;
}