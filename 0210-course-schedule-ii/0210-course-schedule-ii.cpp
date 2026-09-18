class Solution {
public:
    vector<int> bfs(unordered_map<int, vector<int>>& adj, vector<int>& inD){
        queue<int> q;
        for(int i = 0; i < inD.size(); i++){
            if(inD[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt += 1;
            ans.push_back(u);

            for(auto &v:adj[u]){
                inD[v]--;
                if(inD[v] == 0){
                    q.push(v);
                }
            }
        }

        return (cnt == inD.size() ? ans : vector<int>{});
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inD(numCourses, 0);

        for(auto &it:prerequisites){
            int u = it[0], v = it[1];
            adj[v].push_back(u);
            inD[u]++;
        }

        return bfs(adj, inD);
    }
};