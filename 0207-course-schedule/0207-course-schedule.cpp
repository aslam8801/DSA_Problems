class Solution {
public:
    void bfs(unordered_map<int, vector<int>>& adj, queue<int>& q, vector<int>& inD, int& cnt){

        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt += 1;
            for(auto &v:adj[u]){
                inD[v]--;
                if(inD[v] == 0){
                    q.push(v);
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inD(numCourses, 0);
        for(auto& it:prerequisites){
            int u = it[0], v = it[1];
            adj[v].push_back(u);
            inD[u]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inD[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        bfs(adj, q, inD, cnt);

        return (cnt == numCourses ? true : false);

    }
};