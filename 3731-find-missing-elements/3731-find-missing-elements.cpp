class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxE = *max_element(nums.begin(), nums.end());
        int minE = *min_element(nums.begin(), nums.end());
        int n = maxE - minE;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int j = 0;
        for(int i = minE; i <= maxE; i++){
            if(j >= n){
                break;
            }
            if(nums[j] != i){
                ans.push_back(i);
            }
            if(nums[j] == i){
                j++;
            }
        }
        return ans;
    }
};