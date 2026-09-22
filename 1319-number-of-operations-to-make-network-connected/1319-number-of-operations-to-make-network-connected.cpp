class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionT(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[y_parent] = x_parent;
            rank[x_parent] += 1;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }

        parent.resize(n);
        rank.assign(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

         

        for(auto &curr:connections){
            unionT(curr[0], curr[1]);
        }

        int component = 0;

        for(int i = 0; i < n; i++){
            if(i == parent[i]){
                component += 1;
            }
        }

        return component-1;
    }
};