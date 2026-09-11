class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int freq[10] = {};

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int i = 1; i <= 9; i++) {          // hundreds
            for (int j = 0; j <= 9; j++) {      // tens
                for (int k = 0; k <= 8; k += 2) { // units
                   
                    // Check if digits are available
                    int needI = 1;
                    int needJ = 1;
                    int needK = 1;

                    if (i == j) needI++;
                    if (i == k) needI++;
                    if (j == k) needJ++;

                    if (freq[i] >= needI &&
                        freq[j] >= needJ &&
                        freq[k] >= needK) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};