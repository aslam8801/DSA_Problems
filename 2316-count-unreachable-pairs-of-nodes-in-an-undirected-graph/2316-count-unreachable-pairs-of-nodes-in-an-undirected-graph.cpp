class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionT(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);

        if(x_par == y_par) {
            return;
        }

        if(rank[x_par] > rank[y_par]) {
            parent[y_par] = x_par;
        }
        else if(rank[x_par] < rank[y_par]) {
            parent[x_par] = y_par;
        }
        else {
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        rank.assign(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto &edge : edges) {
            unionT(edge[0], edge[1]);
        }

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[find(i)]++;
        }

        long long sum = 0;
        long long prev = 0;

        for(auto &[key, size] : mp) {
            sum += prev * size;
            prev += size;
        }

        return sum;
    }
};