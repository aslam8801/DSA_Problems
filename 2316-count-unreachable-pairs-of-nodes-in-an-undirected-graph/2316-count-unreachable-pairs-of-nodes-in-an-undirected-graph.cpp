class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& vis, int& cnt){
        vis[u] = true;
        cnt += 1;
        for(auto &v:adj[u]){
            if(!vis[v]){
                dfs(adj, v, vis, cnt);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto &curr:edges){
            int u = curr[0], v = curr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n, false);
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int cnt = 0;
                dfs(adj, i, vis, cnt);
                if(cnt != 0)
                ans.push_back(cnt);
            }
        }
        if(ans.size() == 1){
            return 0;
        }
        
        long long sum = 0;
long long prev = 0;

for(int size : ans) {
    sum += prev * size;
    prev += size;
}

        return sum;
    }
};