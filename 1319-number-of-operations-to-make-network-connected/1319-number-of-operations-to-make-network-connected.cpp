class Solution {
public:
    void dfs(vector<vector<int>>& connections, int u, vector<bool>& vis){
        vis[u] = true;

        for(auto &v:connections[u]){
            if(!vis[v]){
                dfs(connections, v, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        int component = 0;
         vector<vector<int>> adj(n);

        for(auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, i, vis);
                component += 1;
            }
        }

        return component - 1;
    }
};