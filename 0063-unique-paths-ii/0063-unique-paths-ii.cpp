class Solution {
public:
    int dp[100][100];
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i == 0 && j == 0){
            return 1;
        }
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int up = 0, left = 0;
        if(i > 0 && grid[i-1][j] != 1){
            up = solve(i-1, j, grid);
        }
        if(j > 0 && grid[i][j-1] != 1){
            left = solve(i, j-1, grid);
        }
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        return solve(m-1, n-1, obstacleGrid);
        
    }
};