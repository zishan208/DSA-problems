class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        int count = 0;

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                int i_index = temp.first;
                int j_index = temp.second;

                if (i_index + 1 < rows && grid[i_index+1][j_index] == 1) {
                    grid[i_index+1][j_index] = 2;
                q.push({i_index+1, j_index});
                    fresh--;
                    rotted = true;
                }
                if (i_index - 1 >= 0 && grid[i_index-1][j_index] == 1) {
                  grid[i_index-1][j_index] = 2;
                    q.push({i_index-1, j_index});
                    fresh--;
                    rotted = true;
                }
                if (j_index + 1 < cols && grid[i_index][j_index+1] == 1) {
                    grid[i_index][j_index+1] = 2;
                    q.push({i_index, j_index+1});
                    fresh--;
                    rotted = true;
                }
                if (j_index - 1 >= 0 && grid[i_index][j_index-1] == 1) {
                    grid[i_index][j_index-1] = 2;
                    q.push({i_index, j_index-1});
                    fresh--;
                    rotted = true;
                }
            }
            if (rotted) count++;
        }

        return fresh == 0 ? count : -1;
    }
};