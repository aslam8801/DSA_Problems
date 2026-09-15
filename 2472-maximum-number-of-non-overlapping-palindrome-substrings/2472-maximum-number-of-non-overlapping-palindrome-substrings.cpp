class Solution {
public:
    int dp[2001][2001];
    bool isPalindrome(string& s, int i, int j){

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i += 1;
            j -= 1;
        }
        return true;
    }
    int solve(string& s, int i, int j, int k, int n){
        if(i >= n || j >= n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(isPalindrome(s, i, j)){
            int take = 1 + solve(s, j+1, j+k, k, n);
            int grow = solve(s, i, j+1, k, n);
            int slide = solve(s, i+1, j+1, k, n);
            return dp[i][j] = max({take, grow, slide});
        }
        
        int grow = solve(s, i, j+1, k, n);
        int slide = solve(s, i+1, j+1, k, n);
        return dp[i][j] = max(grow, slide);
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k <= 1){
            return n;
        }
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, k-1, k, n);
    }
};