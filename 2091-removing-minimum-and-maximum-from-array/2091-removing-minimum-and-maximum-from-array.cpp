class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int leftIdx = min(minIdx, maxIdx);
        int rightIdx = max(minIdx, maxIdx);

        int option1 = (leftIdx+1) + (nums.size()-rightIdx);
        int option2 = rightIdx+1;
        int option3 = nums.size()-leftIdx ;

        return min({option1, option2, option3});
    }
};