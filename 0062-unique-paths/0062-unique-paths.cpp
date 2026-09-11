class Solution {
public:
    int dp[101][101];
    int solve(int sr, int sc, int m, int n){
        if(sr == m-1 && sc == n-1){
            return 1;
        }
        if(sr >= m || sc >= n){
            return 0;
        }
        if(dp[sr][sc] != -1){
            return dp[sr][sc];
        }

        return dp[sr][sc] = solve(sr+1, sc, m, n) + solve(sr, sc+1, m, n);
    }
    int uniquePaths(int m, int n) {
        int sr = 0, sc = 0;
        memset(dp, -1, sizeof(dp));
        return solve(sr, sc, m, n);
    }
};