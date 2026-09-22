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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }

        for(string &s:equations){
            if(s[1] == '='){
                unionT(s[0]-'a', s[3]-'a');
            }
        }

        for(string &s:equations){
            if(s[1] == '!'){
                int first = s[0] - 'a';
                int  second = s[3] - 'a';

                if(find(first) == find(second)){
                    return false;
                }
            }
        }

        return true;
    }
};