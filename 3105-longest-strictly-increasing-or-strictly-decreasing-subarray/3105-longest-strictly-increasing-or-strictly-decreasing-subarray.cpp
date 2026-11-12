class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        int maxLength = 0;

        for(int i = 0; i < nums.size()-1; i++){
            int currLength = 0;
            bool order = true;
            if(nums[i] < nums[i+1]){
                order = true;
            }else{
                order = false;
            }
            for(int j = i+1; j < nums.size(); j++){
                if((nums[j] <= nums[j-1] && order) || (nums[j] >= nums[j-1] && !order)){
                    break;
                }
                currLength += 1;
            }

            maxLength = max(maxLength, currLength + 1);
        }

        return maxLength;
    }
};