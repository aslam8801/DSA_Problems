class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int curr, vector<int>& color, int currColor){
        queue<int> q;
        q.push(curr);
        color[curr] = currColor;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto& v:graph[u]){
                if(color[v] == color[u]){
                    return false;
                }

                if(color[v] == -1){
                    int colorV = 1 - color[u];
                    color[v] = colorV;
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                bool ans = bfs(graph, i, color, 1);
                if(ans == false){
                    return ans;
                }
            }
        }

        return true;
    }
};