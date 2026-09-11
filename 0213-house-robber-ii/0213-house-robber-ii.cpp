class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            dp[i] = max(
                nums[i-1] + (i >= 2 ? dp[i-2] : 0),
                dp[i-1]
            );
        }

        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        vector<int> temp1, temp2;

        for(int i = 0; i < n; i++) {
            if(i != 0)
                temp1.push_back(nums[i]);

            if(i != n-1)
                temp2.push_back(nums[i]);
        }

        return max(rob1(temp1), rob1(temp2));
    }
};