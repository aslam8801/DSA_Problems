
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int K) {
        int n = nums.size();

        deque<pair<int, int>> dq;
        long long cost = 0;
        long long ans = 0;

        int r = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int cnt = 1;

            // Add nums[i] to the front
            while (!dq.empty() && dq.front().first <= nums[i]) {
                auto [val, freq] = dq.front();
                dq.pop_front();

                cost += 1LL * (nums[i] - val) * freq;
                cnt += freq;
            }

            dq.push_front({nums[i], cnt});

            // Shrink window from the right
            while (cost > K) {
                int val = nums[r];

                cost -= dq.back().first - val;

                dq.back().second--;

                if (dq.back().second == 0) {
                    dq.pop_back();
                }

                r--;
            }

            // Count valid subarrays starting at i
            ans += r - i + 1;
        }

        return ans;
    }
};
