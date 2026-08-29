class Solution {
    private:
    void calldfs(vector<vector<char>>& board, int i, int j, int row, int col) {
        if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != 'O') {
            return;
        }

    board[i][j] = 'T';

        if (i + 1 < row) calldfs(board, i + 1, j, row, col);
        if (i - 1 >= 0) calldfs(board, i - 1, j, row, col);
        if (j + 1 < col) calldfs(board, i, j + 1, row, col); 
        if (j - 1 >= 0) calldfs(board, i, j - 1, row, col);
    }

public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O') calldfs(board, 0, j, row, col);
            if (board[row - 1][j] == 'O') calldfs(board, row - 1, j, row, col);
        }
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') calldfs(board, i, 0, row, col);
            if (board[i][col - 1] == 'O') calldfs(board, i, col - 1, row, col);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
         if (board[i][j] == 'T') {
                    board[i][j] = 'O';  
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X'; 
                }
            }
        }
    }
};