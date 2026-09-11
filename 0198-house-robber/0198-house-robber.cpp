class Solution {
public:
    int dp[100+1];
    int solve(vector<int>& nums, int n){
        if(n <= 0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = max(nums[n-1] + solve(nums, n-2), solve(nums, n-1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, n);
    }
};