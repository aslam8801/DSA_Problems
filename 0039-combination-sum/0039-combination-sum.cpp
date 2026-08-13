class Solution {
public:
    set<vector<int>> s;
    void subs(int idx, vector<int>& curr, vector<int>& candidates, int n, vector<vector<int>>& ans,
    int target, int& sum){
        if(idx >= n){
            if(sum == target){
                if(s.find(curr) == s.end()){
                    s.insert(curr);
                    ans.push_back(curr);
                }
            }
            return ;
        }

        if(sum + candidates[idx] <= target){
            sum += candidates[idx];
            curr.push_back(candidates[idx]);
            subs(idx, curr, candidates, n, ans, target, sum);
            sum -= candidates[idx];
            curr.pop_back();
        }
        subs(idx+1, curr, candidates, n, ans, target, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int idx = 0, sum = 0;
        vector<vector<int>> ans;
        vector<int> curr;
        subs(idx, curr, candidates, n, ans, target, sum);
        return ans;
    }
};