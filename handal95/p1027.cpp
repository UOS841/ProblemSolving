#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct{
    long long x;
    long long y;
}Point;

long long ccw(Point p1, Point p2, Point p3){
    long long area = (
        (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - 
        (p1.x*p3.y + p2.x*p1.y + p3.x*p2.y) 
    );
    return area;
}

int main(){
    int N;
    cin >> N;
    vector<Point> buildings(N + 1);

    for(long long i = 1; i <= N; i++){
        Point building;
        building.x = i;
        cin >> building.y;
        buildings[i] = building;
    }

    vector<int> reachable(N + 1, 0);
    for(int i = 1; i < N; i++){
        Point pivot = buildings[i+1];
        reachable[i]++;
        reachable[i+1]++;
        for(int j = i + 2; j <= N; j++){
            long long ccw_area = ccw(buildings[i], pivot, buildings[j]);
            if(ccw_area > 0){
                pivot = buildings[j];
                reachable[i]++;
                reachable[j]++;
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= N; i++){
        answer = max(answer, reachable[i]);
    }
    cout << answer;
}