
class Solution {
public:
    const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int even = 1, odd = 0;
        int sum = 0;
        int cnt = 0;

        for(int x : arr) {
            sum += x;

            if(sum % 2 == 0) {
                cnt = (cnt + odd) % MOD;
                even++;
            }
            else {
                cnt = (cnt + even) % MOD;
                odd++;
            }
        }

        return cnt;
    }
};
