#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int H, W; //세로길이, 가로길이
  vector<int> block; //블록높이
  cin >> H >> W;
  block.resize(W);
  for(int i=0; i<W; i++){
    cin >> block[i];
  }
  int now = 0;
  int start = -1; //시작 인덱스
  int end = -1; //끝 인덱스
  bool isStart = false;
  int waters = 0;
  while(0 <= now && now < W){
    if(block[now] > block[now+1] && !isStart){
      start = now;
      cout << "start:" << start <<'\n';
      isStart = true;
    }
    if(block[now] < block[now+1] && isStart){
      if(block[now+1] >= block[now+2] || now+1 == W-1){
        end = now+1;
        cout << "end:" << end << '\n';

        //start, end 비교
        int height = (block[start] <= block[end])? block[start] : block[end];
        for(int i=start+1; i<end; i++){
          waters += height - block[i];
        }
        isStart = false;
      }
    }
    now++;
  }
  cout << waters;
}