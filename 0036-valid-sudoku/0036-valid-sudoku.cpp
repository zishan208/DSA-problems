#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int i = 0; i < 9; i++) {
            unordered_map<char,int> um;
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    if (um[c]++) return false;
                }
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            unordered_map<char,int> um;
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];
                if (c != '.') {
                    if (um[c]++) return false;
                }
            }
        }

        // Check 3x3 sub-boxes
        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                unordered_map<char,int> um;
                for (int i = boxRow * 3; i < boxRow * 3 + 3; i++) {
                    for (int j = boxCol * 3; j < boxCol * 3 + 3; j++) {
                        char c = board[i][j];
                        if (c != '.') {
                            if (um[c]++) return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};