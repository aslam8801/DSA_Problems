class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, maxSum = 0, rsum = 0;

        for(int i = 0; i < k; i++){
            lsum += cardPoints[i];
        }
        maxSum = lsum;
        int rIdx = cardPoints.size()-1;
        for(int i = k-1; i >= 0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rIdx];
            rIdx-=1;
            maxSum = max(maxSum, lsum + rsum);
        }
        return maxSum;
    }
};