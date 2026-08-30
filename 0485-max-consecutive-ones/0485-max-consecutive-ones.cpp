class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int maxL = 0;
        int curr = 0;
        int i = 0, j = 0;
        while(j < n){
            if(nums[j] != 1){
                maxL = max(curr, maxL);
                curr = 0;
                i = j;
            }else{
                curr += 1;
            }
            j++;
        }
        maxL = max(maxL, curr);
        return maxL;
    }
};