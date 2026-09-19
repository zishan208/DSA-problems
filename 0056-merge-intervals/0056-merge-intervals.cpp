class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<vector<int>> ans;
        if (n == 0) return ans;


        if (n == 1) return intervals;

        sort(intervals.begin(), intervals.end(), cmp);

        int first = intervals[0][0];
        int second = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] > second) {
                ans.push_back({first, second});
                first = intervals[i][0];
                second = intervals[i][1];
            } else {
                second = max(second, intervals[i][1]);
            }
        }
        ans.push_back({first, second});
        return ans;
    }
};