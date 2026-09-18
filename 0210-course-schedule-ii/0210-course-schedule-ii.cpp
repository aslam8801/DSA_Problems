class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj,
             int u,
             vector<bool>& vis,
             vector<bool>& inRec,
             stack<int>& st) {

        vis[u] = true;
        inRec[u] = true;

        for(auto &v : adj[u]) {

            if(!vis[v]) {
                if(dfs(adj, v, vis, inRec, st)) {
                    return true;
                }
            }
            else if(inRec[v]) {
                return true;   // cycle
            }
        }

        inRec[u] = false;
        st.push(u);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;

        for(auto &it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> inRec(numCourses, false);

        stack<int> st;

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {
                if(dfs(adj, i, vis, inRec, st)) {
                    return {};     // cycle exists
                }
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};