#include <iostream>
#include <vector>


using namespace std;
typedef vector<vector<int>> Map;

int N;
int dfs(int size, int up, int down, int right, int left){
    if(size == 1){
        return 0;
    }

    for(int r = up; r < down ; r++){
        int value = 0;
        // left 개발
        for(int c = left ; c < down)
    }


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    Map map(N, vector<int>(N));
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            cin >> map[r][c];
        }
    }
}


/*
SELECT user_id AS '고객 아이디', sum(l.price) FROM customer c
    LEFT OUTER JOIN orderInfo o ON c.user_id = o.buyer_id
    LEFT OUTER JOIN library l ON o.book_id = l.book_id
    WHERE c.membership = 1
    GROUP BY user_id;



*/