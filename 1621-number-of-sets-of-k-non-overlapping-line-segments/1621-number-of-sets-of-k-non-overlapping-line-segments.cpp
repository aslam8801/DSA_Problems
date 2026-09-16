class Solution {
public:
    int dp[1001][1001];
    const int MOD = 1e9 + 7;

    int solve(int n, int k, int i) {
        if (k == 0) {
            return 1;
        }

        if (i >= n) {
            return 0;
        }

        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        // Skip current point
        int skip = solve(n, k, i + 1);

        // Take: choose j > i
        int take = 0;

        for (int j = i + 1; j < n; j++) {
            take = (take + solve(n, k - 1, j)) % MOD;
        }

        return dp[i][k] = (skip + take) % MOD;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, 0);
    }
};