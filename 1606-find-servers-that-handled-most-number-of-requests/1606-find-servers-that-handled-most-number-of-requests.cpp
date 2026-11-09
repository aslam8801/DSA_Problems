
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finish_time, server_id}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release all servers whose requests are completed
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // No server available
            if (available.empty()) {
                continue;
            }

            // Find the first available server >= (i % k)
            int target = i % k;

            auto it = available.lower_bound(target);

            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            available.erase(it);

            count[server]++;

            // Mark server as busy
            busy.push({(long long)arrival[i] + load[i], server});
        }

        // Find maximum requests handled
        int mx = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
