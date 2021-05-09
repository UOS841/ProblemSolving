#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int groups; //걸그룹 수
  int quizzes; //퀴즈 수
  vector< vector<string> > info;
  cin >> groups >> quizzes;
  info.resize(groups);
  for(int i=0; i<groups; i++){
    string grp; //팀 이름
    int peoples; //인원 수
    priority_queue<string, vector<string>, greater<string>> pq;
    cin >> grp >> peoples;
    info[i].resize(peoples+1);
    info[i][0] = grp; //팀이름 등록
    for(int j=1; j<=peoples; j++){
      string girl;
      cin >> girl;
      pq.push(girl); //우선순위큐 - 사전순
    }
    for(int j=1; j<=peoples; j++){ //멤버이름 등록
      info[i][j] = pq.top();
      pq.pop();
    }
  }

  for(int i=0; i<quizzes; i++){
    string quiz;
    int quizType;
    cin >> quiz >> quizType;
    if(quizType == 0){ //팀이름 주어지는 경우
      for(int j=0; j<groups; j++){
        if(info[j][0] == quiz){
          for(int k=1; k<info[j].size(); k++){
            cout << info[j][k] << '\n'; //멤버이름 사전순 출력
          }
          break;
        }
      }
    }
    else if(quizType == 1){ //멤버이름 주어지는 경우
      for(int j=0; j<groups; j++){
        for(int k=1; k<info[j].size(); k++){
          int keepGoing = quiz.compare(info[j][k]);
          if(keepGoing == 0){
            //일치
            cout << info[j][0] << '\n';
          }
          else if(keepGoing == -1){
            //다음 그룹으로 넘어가기
            break;
          }
          else if(keepGoing == 1){
            //quiz가 사전순으로 더 이름. 계속 진행
            continue;
          }
        }
      }
    }
  }
}