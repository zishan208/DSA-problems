class Solution {
private:
    bool dfs(char node, int i, int j, int prev_i, int prev_j, 
             int row, int col, vector<vector<char>>& grid, 
             vector<vector<bool>>& visited) {
        // Mark current as visited
        visited[i][j] = true;

        // Check 4 directions
        if (i + 1 < row && grid[i + 1][j] == node) {
            if (visited[i + 1][j]) {
                if (!(i + 1 == prev_i && j == prev_j)) return true;
            } else {
                if (dfs(node, i + 1, j, i, j, row, col, grid, visited)) return true;
            }
        }
        if (i - 1 >= 0 && grid[i - 1][j] == node) {
            if (visited[i - 1][j]) {
                if (!(i - 1 == prev_i && j == prev_j)) return true;
            } else {
                if (dfs(node, i - 1, j, i, j, row, col, grid, visited)) return true;
            }
        }
        if (j + 1 < col && grid[i][j + 1] == node) {
            if (visited[i][j + 1]) {
                if (!(i == prev_i && j + 1 == prev_j)) return true;
            } else {
                if (dfs(node, i, j + 1, i, j, row, col, grid, visited)) return true;
            }
        }
        if (j - 1 >= 0 && grid[i][j - 1] == node) {
            if (visited[i][j - 1]) {
                if (!(i == prev_i && j - 1 == prev_j)) return true;
            } else {
                if (dfs(node, i, j - 1, i, j, row, col, grid, visited)) return true;
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        if (row < 2 || col < 2) return false;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid[i][j], i, j, -1, -1, row, col, grid, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};