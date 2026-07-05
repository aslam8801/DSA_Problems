class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, maxLen = 0, zeros = 0;

        while(r < n){
            if(nums[r] == 0){
                zeros += 1;
            }
            if(zeros <= k){
                maxLen = max(maxLen, r-l+1);
            }
            while(zeros > k){
                if(nums[l] == 0){
                    zeros -= 1;
                }
                l += 1;
            }
            r += 1;
        }
        return maxLen;
    }
};