class Solution {
private:
    bool c(vector<vector<char>>& grid, int i, int j, vector<vector<vector<int>>>& dp,
           int row, int col, int open) {
        if (i >= row || j >= col) return false;
        if (open < 0) return false;

        if (grid[i][j] == '(') open++;
        else open--;

        if (open < 0) return false;  

        if (i == row - 1 && j == col - 1) {
            return open == 0;
        }

        if (dp[i][j][open] != -1) return dp[i][j][open];

        bool down = c(grid, i + 1, j, dp, row, col, open);
        bool right = c(grid, i, j + 1, dp, row, col, open);

        return dp[i][j][open] = (down || right);
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<vector<int>>> dp(row,
            vector<vector<int>>(col, vector<int>(row + col + 1, -1)));

        return c(grid, 0, 0, dp, row, col, 0);
    }
};