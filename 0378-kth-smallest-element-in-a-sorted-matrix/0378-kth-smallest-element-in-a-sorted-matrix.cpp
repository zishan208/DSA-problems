class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        for (int i = 0; i < row; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int ans = -1;

        for (int i = 0; i < k; i++) {
            auto [val, r, c] = pq.top();
            pq.pop();
            ans = val;

            if (c + 1 < col) {
                pq.push({matrix[r][c + 1], r, c + 1});
            }
        }

        return ans;
    }
};