class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1, cnt1 = 0;
        int ele2, cnt2 = 0;

        for(int x:nums){
            if(ele1 == x){
                cnt1 += 1;
            }else if(ele2 == x){
                cnt2 += 1;
            }else if(cnt1 == 0){
                cnt1 = 1;
                ele1 = x;
            }else if(cnt2 == 0){
                cnt2 = 1;
                ele2 = x;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        

        int cnt3 = 0, cnt4 = 0;
        for(int x:nums){
            if(x == ele1){
                cnt3 += 1;
            }else if(x == ele2){
                cnt4 += 1;
            }
        }

        int n = nums.size();
        if(cnt3 > n/3){
            ans.push_back(ele1);
        }

        if(cnt4 > n/3){
            ans.push_back(ele2);
        }

        return ans;
    }
};