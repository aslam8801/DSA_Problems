class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = k-1, r = n-1;
        int lSum = 0, rSum = 0;
        int total = INT_MIN;
        for(int i = 0; i < k; i++){
            lSum += cardPoints[i];
        }

        total = max(total, lSum);

        while(l >= 0){
            lSum -= cardPoints[l];
            l -= 1;
            rSum += cardPoints[r];
            r -= 1;
            total = max(total, lSum + rSum);
        }
        return total;
    }
};