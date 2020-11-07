#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>

using namespace std;



typedef struct{
    double x;
    double y;
}Point;

vector<int> parent;
vector<pair<Point, int>> vec;

int find(int p) {
	if (parent[p] == p) return p;
	return parent[p] = find(parent[p]);
}

void merge(int a, int b) {
	a = find(a);
    b = find(b);
	if (a != b) {
        parent.at(b) = a;
    }
}

bool dist(Point p1, Point p2, long long dist){
    long long x2 = pow((p1.x - p2.x), 2);
    long long y2 = pow((p1.y - p2.y), 2);
    long long r2 = pow(dist, 2);
    return (x2 + y2) <= r2;
}

int main(){
    int T;
    cin >> T;
    while(T-->0){
        int N;
        cin >> N;
        vec.clear();
        vec.resize(N);

        parent.clear();
        parent.resize(N);

        int answer = N;
        for(int i = 0 ; i < N; i++){
            cin >> vec[i].first.x >> vec[i].first.y >> vec[i].second;
            parent[i] = i;
        }

        for(int i = 0 ; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(find(i) == find(j))
                    continue;
                int range = vec[i].second + vec[j].second;
                if(dist(vec[i].first, vec[j].first, range)){
                    merge(i, j);
                    answer--;
                }
            }
        }
        
        cout << answer << endl;
    }
}