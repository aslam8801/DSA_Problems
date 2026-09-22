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
        int x_par = find(x);
        int y_par = find(y);

        if(x_par == y_par){
            return ;
        }

        if(rank[x_par] > rank[y_par]){
            parent[y_par] = x_par;
        }else if(rank[x_par] < rank[y_par]){
            parent[x_par] = y_par;
        }else{
            parent[y_par] = x_par;
            rank[x_par] += 1;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto &vec:edges){
            int u = vec[0], v = vec[1];
            unionT(u, v);
        }

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[find(i)]++; // why dont we are using parent[i]
        }

        long long sum = 0, prev = 0;
        for(auto &[key, size]:mp){
            sum += (prev*size);
            prev += size;
        }

        return sum;
    }
};