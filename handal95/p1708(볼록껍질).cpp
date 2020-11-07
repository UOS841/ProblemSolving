#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct{
    double x;
    double y;
}Point;

long long ccw(Point p1, Point p2, Point p3){
    long long area = (
        (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - 
        (p1.x*p3.y + p2.x*p1.y + p3.x*p2.y) 
    );
    return area;
}
vector<Point> points;

bool sort_y(Point p1, Point p2){
    if(p1.y != p2.y) 
        return p1.y < p2.y;
    return p1.x < p2.x;
}

bool sort_clockwise(Point p1, Point p2){
    long long area = ccw(points[0], p1, p2);
    if (area != 0) 
        return area > 0;
    return (p1.x + p1.y) < (p2.x + p2.y);
}


int main(){
    int N;
    cin >> N;
    points.resize(N);
    for(int i = 0; i < N; i++){
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), sort_y);
    sort(points.begin() + 1, points.end(), sort_clockwise);

    stack<Point> selected_points;
    selected_points.push(points[0]); // y 가 제일 작은녀석
    selected_points.push(points[1]); // 가장 각도가 작은녀석

    for(int i = 2; i < N ; i++){
        while(selected_points.size() >= 2){
            Point second = selected_points.top();
            selected_points.pop();
            Point first = selected_points.top();

            long long area = ccw(first, second, points[i]);
            if(area > 0){
                selected_points.push(second);
                break;
            }
        }
        selected_points.push(points[i]);
    }
    cout << selected_points.size();
}