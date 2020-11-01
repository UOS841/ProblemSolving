#include <iostream>

using namespace std;

typedef struct{
    int x;
    int y;
}Point;

int ccw(Point p1, Point p2, Point p3){
    int area = (
        (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - 
        (p1.x*p3.y + p2.x*p1.y + p3.x*p2.y) 
    );
    return area;
}

int main() {
    Point points[3];
    for(int i = 0 ; i < 3; i++){
        cin >> points[i].x >> points[i].y;
    }

    int area = ccw(points[0], points[1], points[2]) / 2;

    if(area > 0)
        cout << "1";
    else if(area < 0) 
        cout << "-1";
    else
        cout << "0";
}
