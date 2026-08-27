class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int count = 0;

        for (int i = 0; i < row; i++) {
     for (int j = 0; j < col; j++) {
      if (grid[i][j] == '1' && !visited[i][j]) {
          queue<pair<int, int>> q;
                    
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto it = q.front();
                       q.pop();

                        int x = it.first;
                        int y = it.second;
                        if (x - 1 >= 0 && grid[x - 1][y] == '1' && !visited[x - 1][y]) {
                            visited[x - 1][y] = true;
                         q.push({x - 1, y});
                        }
                        if (x + 1 < row && grid[x + 1][y] == '1' && !visited[x + 1][y]) {
                      visited[x + 1][y] = true;
                            q.push({x + 1, y});
                        }
                        if (y + 1 < col && grid[x][y + 1] == '1' && !visited[x][y + 1]) {
                      visited[x][y + 1] = true;
                            q.push({x, y + 1});
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1' && !visited[x][y - 1]) {
                            visited[x][y - 1] = true;
                            q.push({x, y - 1});
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};