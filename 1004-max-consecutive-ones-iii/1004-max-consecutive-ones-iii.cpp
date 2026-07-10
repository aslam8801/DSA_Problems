class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int maxLen = 0;
        int zeros = 0;
        while(r < n){
            if(nums[r] == 0){
                zeros++;
            }
            while(zeros > k){
                if(nums[l] == 0){
                    zeros-=1;
                }
                l = l+1;
            }
            maxLen = max(maxLen, r-l+1);
            r = r+1;
        }
        return maxLen;
    }
};