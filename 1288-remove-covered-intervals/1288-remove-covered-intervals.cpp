class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        auto lambda = [](vector<int>& v1, vector<int>& v2){
            if(v1[0] == v2[0]){
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i = 1; i < n; i++){
            if(res.back()[0] <= intervals[i][0] && res.back()[1] >= intervals[i][1]){
                continue;
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res.size();
    }
};