class Solution {

private:
    void check(int i, int j, vector<vector<int>>& heights, int rows, int cols, vector<vector<bool>>& ocean) {
        ocean[i][j] = true;

       
        if (i + 1 < rows && !ocean[i + 1][j] && heights[i + 1][j] >= heights[i][j])


            check(i + 1, j, heights, rows, cols, ocean);
        if (i - 1 >= 0 && !ocean[i - 1][j] && heights[i - 1][j] >= heights[i][j])


            check(i - 1, j, heights, rows, cols, ocean);
        if (j + 1 < cols && !ocean[i][j + 1] && heights[i][j + 1] >= heights[i][j])

            check(i, j + 1, heights, rows, cols, ocean);
        if (j - 1 >= 0 && !ocean[i][j - 1] && heights[i][j - 1] >= heights[i][j])


            check(i, j - 1, heights, rows, cols, ocean);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> ans;

      
        vector<vector<bool>> zero_row(rows, vector<bool>(cols, false));

        for (int j = 0; j < cols; j++) {

            check(0, j, heights, rows, cols, zero_row);
        }
        for (int i = 0; i < rows; i++) {

            check(i, 0, heights, rows, cols, zero_row);
        }

        vector<vector<bool>> zero_col(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
         check(i, cols - 1, heights, rows, cols, zero_col);
        }
        for (int j = 0; j < cols; j++) {
        check(rows - 1, j, heights, rows, cols, zero_col);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (zero_row[i][j] && zero_col[i][j]) {
                  ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};