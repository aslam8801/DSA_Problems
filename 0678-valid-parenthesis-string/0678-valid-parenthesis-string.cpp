class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // minimum possible number of unmatched '('
        int high = 0;  // maximum possible number of unmatched '('

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                // '*' can be '(' or ')' or empty
                low--;
                high++;
            }

            // low cannot be negative
            low = max(0, low);

            // Even the maximum possibility has too many ')'
            if (high < 0) {
                return false;
            }
        }

        // We must be able to have exactly 0 unmatched '('
        return low == 0;
    }
};