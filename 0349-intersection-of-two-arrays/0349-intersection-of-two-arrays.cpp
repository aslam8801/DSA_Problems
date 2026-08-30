class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_set<int> s, s2;

        for(int x:nums1){
            s.insert(x);
        }

        vector<int> ans;
        for(int x:nums2){
            if(s.find(x) != s.end() && s2.find(x) == s2.end()){
                ans.push_back(x);
                s2.insert(x);
            }
        }

        return ans;
    }
};