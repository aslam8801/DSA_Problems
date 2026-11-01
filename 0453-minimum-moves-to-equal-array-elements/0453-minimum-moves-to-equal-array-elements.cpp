class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int x:nums){
            mp[x]+=1;
        }


        if(mp.size() == 1){
            return 0;
        }

        int max_ele = *max_element(nums.begin(), nums.end());
        int min_ele = *min_element(nums.begin(), nums.end());

        int moves = 0;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] == min_ele){
                continue;
            }

            int curr = nums[i] - min_ele;
            moves += curr;
        }

        return moves;
    }
};