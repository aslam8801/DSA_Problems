class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int sum = INT_MAX;

        for(int i = 0; i < n; i++){
            int currSum = 0;

            for(int j = i; j < n; j++){
                currSum += nums[j];

                int len = j - i + 1;

                if(len >= l && len <= r && currSum > 0){
                    sum = min(sum, currSum);
                }

                if(len >= r) break;
            }
        }

        return sum == INT_MAX ? -1 : sum;
    }
};