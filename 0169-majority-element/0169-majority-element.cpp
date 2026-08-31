class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int x:nums){
            mp[x]++;
        }

        int maxEle = nums[0];
        int maxFre = INT_MIN;
        for(auto it:mp){
            if(maxFre < it.second){
                maxEle = it.first;
                maxFre = it.second;
            }
        }

        return maxEle;
    }
};