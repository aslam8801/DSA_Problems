
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // Step 1: Precompute cost of every substring
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int len = 2; len <= n; len++) {
            for (int d = 1; d < len; d++) {

                // d must be a proper divisor of len
                if (len % d != 0) continue;

                int groupLen = len / d;

                for (int i = 0; i + len <= n; i++) {
                    int changes = 0;

                    // Check all d groups
                    for (int r = 0; r < d; r++) {

                        // Make each group a palindrome
                        for (int t = 0; t < groupLen / 2; t++) {
                            int left = i + r + t * d;

                            int right = i + r +
                                (groupLen - 1 - t) * d;

                            if (s[left] != s[right]) {
                                changes++;
                            }
                        }
                    }

                    cost[i][i + len - 1] =
                        min(cost[i][i + len - 1], changes);
                }
            }
        }

        // Step 2: DP for partitioning
        vector<vector<int>> dp(
            k + 1, vector<int>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {

                // Starting index of last substring
                for (int j = 2 * (p - 1); j <= i - 2; j++) {

                    if (dp[p - 1][j] == INF) continue;

                    dp[p][i] = min(
                        dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
