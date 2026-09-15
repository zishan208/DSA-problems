class Solution {
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int total = intervals.size();
        if (total == 0) return 0; 

        vector<pair<int,int>> p;

        for (auto& c : intervals) {   
            int first = c[0];
            int second = c[1];
            p.push_back(make_pair(first, second));
        }

        sort(p.begin(), p.end(), cmp); 

        int count = 1;
        int endNum = p[0].second; 

        for (int i = 1; i < total; i++) {
            if (p[i].first >= endNum) { 
                count++;
                endNum = p[i].second;
            }
        }

        return total - count;
    }
};