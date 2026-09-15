class Solution {
  static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int total = intervals.size();
        if (total == 0) return 0; 

        

     

        sort(intervals.begin(), intervals.end(), cmp); 

        int count = 1;
        int endNum = intervals[0][1]; 

        for (int i = 1; i < total; i++) {
            if (intervals[i][0] >= endNum) { 
                count++;
                endNum = intervals[i][1];
            }
        }

        return total - count;
    }
};