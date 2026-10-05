class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> vis(n, -1);
        int ans = -1;
        int timer = 0;

        for (int i = 0; i < n; i++) {

            // Already processed from an earlier traversal
            if (vis[i] != -1)
                continue;

            int curr = i;
            int startTime = timer;

            while (curr != -1 && vis[curr] == -1) {
                vis[curr] = timer++;
                curr = edges[curr];
            }

            // curr is visited and belongs to this traversal
            if (curr != -1 && vis[curr] >= startTime) {
                int cycleLength = timer - vis[curr];
                ans = max(ans, cycleLength);
            }
        }

        return ans;
    }
};