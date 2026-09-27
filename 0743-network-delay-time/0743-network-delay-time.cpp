class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto &vec : times) {
            int u = vec[0], v = vec[1], t = vec[2];
            adj[u].push_back({v, t});
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> result(n + 1, INT_MAX);

        result[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dist > result[node])
                continue;

            for(auto &vec : adj[node]) {
                int adjNode = vec.first;
                int d = vec.second;

                if(dist + d < result[adjNode]) {
                    result[adjNode] = dist + d;
                    pq.push({dist + d, adjNode});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            if(result[i] == INT_MAX)
                return -1;

            ans = max(ans, result[i]);
        }

        return ans;
    }
};