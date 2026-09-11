class Solution {
public:
    int dp[100+1];
    int solve(vector<int>& nums, int n){

        if(n <= 0){
            return 0;
        }

        if(n == 1){
            return nums[0];
        }

        if(n == 2){
            return max(nums[1], nums[0]);
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = max(nums[n-1] + solve(nums, n-2), nums[n-2] + solve(nums, n-3));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, n);
    }
};