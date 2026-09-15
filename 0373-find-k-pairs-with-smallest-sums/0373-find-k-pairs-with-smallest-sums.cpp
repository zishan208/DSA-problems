class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;
        
        for (int j = 0; j < n2 && j < k; j++) {
            pq.push({nums1[0] + nums2[j], 0, j});
        }
        vector<vector<int>> ans;
        while (k-- && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            
            if (i + 1 < n1) {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
            }
        }
        return ans;
    }
};