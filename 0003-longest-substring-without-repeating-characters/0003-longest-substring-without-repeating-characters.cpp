class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;

        vector<int> freq(256, 0);

        for(int i = 0; i < n; i++){

            for(int j = i; j < n; j++){
                if(freq[s[j]] != 0){
                    fill(freq.begin(), freq.end(), 0);
                    break;
                }
                freq[s[j]]++;
                maxLen = max(maxLen , j-i+1);
            }
        }
        return maxLen ;
    }
};