class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& vis, vector<bool>& inR){
        vis[u] = true;
        inR[u] = true;

        for(auto &v:adj[u]){
            if(!vis[v]){
                if(dfs(adj, v, vis, inR)){
                    return true;
                }
            }else if(inR[v] == true){
                return true;
            }
        }
        inR[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for(auto &it:prerequisites){
            int u = it[0], v = it[1];
            adj[v].push_back(u);
        }

        vector<bool> vis(numCourses, false), inR(numCourses, false);
        bool ans = false;
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                ans = dfs(adj, i, vis, inR);
                if(ans){
                    break;
                }
            }
        }
        return (ans ? false : true);
    }
};