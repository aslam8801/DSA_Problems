class Solution {
public:
    void printSubs(int idx, vector<int>& curr, vector<int> nums, int n, vector<vector<int>>& ans){
        if(idx == n){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[idx]);
        printSubs(idx+1, curr, nums, n, ans);
        curr.pop_back();
        printSubs(idx+1, curr, nums, n, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        vector<vector<int>> ans;
        vector<int> curr;
        printSubs(idx, curr, nums, n, ans);
        return ans;
    }
};