#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair<int, int>> flowers;
    for(int i = 0; i < N; i++){
        int s_month, s_day, e_month, e_day;
        cin >> s_month >> s_day >> e_month >> e_day;

        int s_date = s_month * 100 + s_day;
        int e_date = e_month * 100 + e_day - 1;

        flowers.push_back({s_date, e_date});
    }

    sort(flowers.begin(), flowers.end());

    int answer = 0;
    int flowering_date = 0;
    for (int date = 301; date <= 1130; date++){
        cout << "date : " << date << endl;
        bool planted = false;

        for(int i = 0; i < N; i++){
            if(flowers[i].first > date){
                break;
            }

            if(flowers[i].second > flowering_date){
                flowering_date = max(flowers[i].second, flowering_date);
                planted = true;
            }
        }

        if(planted){
            date = flowering_date;
            answer++;
        } else {
            answer = 0;
            break;
        }
    }

    if(flowering_date < 1130){
        answer = 0;
    }

    cout << answer << endl;
}