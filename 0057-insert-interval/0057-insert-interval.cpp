class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int index = 0;

        while (index < n && intervals[index][1] < newInterval[0]) {
            ans.push_back(intervals[index]);
            index++;
        }

     int minimum = newInterval[0];
        int maximum = newInterval[1];

        while (index < n && intervals[index][0] <= newInterval[1]) {
            minimum = min(minimum, intervals[index][0]);
            maximum = max(maximum, intervals[index][1]);
            index++;
        }

        ans.push_back({minimum, maximum});

        while (index < n) {
            ans.push_back(intervals[index]);
            index++;
        }

        return ans;
    }
};