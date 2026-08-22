class Solution {
public:
    int dp[30+1];
    int fibb(int n){
        if(n <= 1){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = fibb(n-1) + fibb(n-2);
    }
    int fib(int n) {
        memset(dp, -1, sizeof(dp));
        return fibb(n);
    }
};