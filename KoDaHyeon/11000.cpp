#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int classes; //수업 개수
  priority_queue<int, vector<int>, greater<int> > classQ; //각 강의실 종료 시간(이른 순서)
  priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > timeQ; //각 수업 시간(이른 순서)
  cin >> classes;
  for(int i=0; i<classes; i++){
    pair<int,int> time;
    cin >> time.first >> time.second;
    timeQ.push(time);
  }
  

  classQ.push(timeQ.top().second);
  timeQ.pop();

  while(!timeQ.empty()){
    int start =  timeQ.top().first;
    int end = timeQ.top().second;
    timeQ.pop();
    if(start >= classQ.top()){
      classQ.pop();
    }
    classQ.push(end);
  }

  cout << classQ.size();
}