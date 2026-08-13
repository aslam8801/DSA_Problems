class Solution {
public:
    set<vector<int>> s;
    void subs(int idx, vector<int>& curr, vector<int>& candidates, int n, vector<vector<int>>& ans, int& sum, int target){
        if(idx >= n){
            if(sum == target){
                if(s.find(curr) == s.end()){
                    s.insert(curr);
                    ans.push_back(curr);
                }
            }
            return ;
        }
        if(sum + candidates[idx] <= target) {
            sum += candidates[idx];
            curr.push_back(candidates[idx]);

            subs(idx, curr, candidates, n, ans, sum, target);

            curr.pop_back();
            sum -= candidates[idx];
        }
        subs(idx+1, curr, candidates, n, ans, sum, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = candidates.size();
        int idx = 0, sum = 0;
        subs(idx, curr, candidates, n, ans, sum, target);
        return ans;
    }
};