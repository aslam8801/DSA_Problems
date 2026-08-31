class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0], cnt = 0;

        for(int x:nums){
            if(cnt == 0){
                ele = x;
                cnt += 1;
            }else if(ele == x){
                cnt++;
            }else{
                cnt--;
            }
        }

        return ele;
    }
};