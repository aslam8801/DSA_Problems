class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());

        int moves = 0;

        for(int x:nums){
            moves += abs(maxEle - x);
        }

        return moves;
    }
};