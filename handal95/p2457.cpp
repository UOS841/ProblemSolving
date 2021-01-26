#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> Flower;
typedef vector<Flower> Flowers;

int main(){
    int N;
    cin >> N;

    Flowers flowers(N);

    for(int i = 0; i < N; i++){
        int s_month, s_day, e_month, e_day;
        cin >> s_month >> s_day >> e_month >> e_day;

        flowers[i].first = s_month * 100 + s_day;
        flowers[i].second = e_month * 100 + e_day - 1;
    }

    sort(flowers.begin(), flowers.end());

    int answer = 0;
    int flowering_date = 0;
    for (int date = 301; date <= 1130; date++){
        bool planted = false;

        for(int i = 0; flowers[i].first < date; i++){
            if(flowers[i].second > flowering_date){
                flowering_date = max(flowers[i].second, flowering_date);
                planted = true;
            }
        }

        if(planted){
            date = flowering_date;
            answer++;
        }
    }

    if(flowering_date < 1130){
        answer = 0;
    }

    cout << answer << endl;
}