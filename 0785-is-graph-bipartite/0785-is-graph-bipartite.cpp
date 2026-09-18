class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int curr, vector<int>& color, int currColor){
        color[curr] = currColor;

        for(auto &v:graph[curr]){
            if(color[v] == currColor ){
                return false;
            }

            if(color[v] == -1){
                int colorV = 1 - currColor;
                if(dfs(graph, v, color, colorV) == false){
                    return false;
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
                bool ans = dfs(graph, i, color, 1);
                if(ans == false){
                    return false;
                }
            }
        }

        return true;
    }
};