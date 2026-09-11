class Solution {
public:
    int dp[200][200];
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i == 0 && j == 0){
            return grid[i][j];
        }
        if(i < 0 || j < 0){
            return INT_MAX;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int left = solve(i, j-1, grid);
        int up = solve(i-1, j, grid);

        return dp[i][j] = grid[i][j] + min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(m-1, n-1, grid);
    }
};