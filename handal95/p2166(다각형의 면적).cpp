#include <iostream>
#include <vector>


using namespace std;


typedef struct{
    double x;
    double y;
}Point;

double ccw(Point p1, Point p2, Point p3){
    double area = (
        (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - 
        (p1.x*p3.y + p2.x*p1.y + p3.x*p2.y) 
    );
    return area;
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);
    for(int i = 0 ; i < N; i++){
        cin >> points[i].x >> points[i].y;
    }

    cout << fixed;
    cout.precision(1);
    double total_area = 0;
    for(int i = 1; i < N-1; i++){
        double area = ccw(points[0], points[i], points[i+1]);
        cout << area << endl;
        total_area += area;  
    }
    cout << llabs(total_area)/2.0 << endl;
}
