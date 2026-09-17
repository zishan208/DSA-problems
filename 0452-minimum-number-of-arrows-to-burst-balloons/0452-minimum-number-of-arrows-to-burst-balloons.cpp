class Solution {
      static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {

            int total = points.size();
        if (total == 0) return 0; 

        

     

        sort(points.begin(), points.end(), cmp); 

        int count = 1;
        int endNum = points[0][1]; 

        for (int i = 1; i < total; i++) {
            if (points[i][0] > endNum) { 
                count++;
                endNum = points[i][1];
            }
        }

        return count;


        
    }
};