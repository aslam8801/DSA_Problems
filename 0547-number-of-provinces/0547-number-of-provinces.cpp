class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& vis){
        vis[u] = true;

        for(auto& v:adj[u]){
            if(!vis[v]){
                dfs(adj, v, vis);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(i != j && isConnected[i][j]) {
                   adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(V, false);
        int cnt = 0;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt += 1;
                dfs(adj, i, vis);
            }
        }

        return cnt;
    }
};