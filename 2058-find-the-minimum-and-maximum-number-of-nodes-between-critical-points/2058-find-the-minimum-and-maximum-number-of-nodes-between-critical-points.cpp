class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vals;

        ListNode* curr = head;

        while(curr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }

        int n = vals.size();

        if(n < 3) {
            return {-1, -1};
        }

        vector<int> cp;

        for(int i = 1; i < n - 1; i++) {
            if((vals[i] > vals[i-1] && vals[i] > vals[i+1]) ||
               (vals[i] < vals[i-1] && vals[i] < vals[i+1])) {
                cp.push_back(i);
            }
        }

        if(cp.size() < 2) {
            return {-1, -1};
        }

        int maxi = cp.back() - cp.front();

        int mini = INT_MAX;

        for(int i = 1; i < cp.size(); i++) {
            mini = min(mini, cp[i] - cp[i-1]);
        }

        return {mini, maxi};
    }
};