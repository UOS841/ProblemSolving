#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> grid;
    grid.resize(n+1, vector<int> (m+1, 0));

    for(auto puddle : puddles){
        grid[puddle[1]-1][puddle[0]-1] = -1;
    }

    grid[0][0]=1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] >= 0) {
                if(grid[i][j+1]>=0) grid[i][j+1] = (grid[i][j+1] + grid[i][j]) %  1000000007;
                if(grid[i+1][j]>=0) grid[i+1][j] = (grid[i+1][j] + grid[i][j]) %  1000000007;
            }
        }
    }
    return grid[n-1][m-1];
}
