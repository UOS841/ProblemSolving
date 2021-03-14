#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> Point;

bool compare(Point p1, Point p2){
    if(p1.second > p2.second){
        return false;
    } else if (p1.second == p2.second) {
        return (p1.first < p2.first);
    } else {
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<Point> points(N);
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    sort(points.begin(), points.end(), compare);
    for(int i = 0; i < N; i++){
        cout << points[i].first << " " << points[i].second << "\n";
    }
}