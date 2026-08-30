class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }

        int j = 0;
        for(int i = 0; i < temp.size(); i++){
            nums[j] = temp[i];
            j++;
        }

        while(j < n){
            nums[j++] = 0;
        }
    }
};