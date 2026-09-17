class Solution {
public:
    void bfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& vis){
        queue<int> q;
        q.push(u);
        vis[u] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &v:adj[node]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(V, false);
        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                bfs(adj, i, vis);
                cnt += 1;
            }
        }

        return cnt;
    }
};