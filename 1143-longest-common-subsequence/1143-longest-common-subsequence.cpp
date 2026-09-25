

class Solution {
    int check(string &text1, string &text2, int idx1, int idx2, int &n1, int &n2, vector<vector<int>> &dp) {
        if (idx1 >= n1 || idx2 >= n2) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if (text1[idx1] == text2[idx2]) {
            return 1 + check(text1, text2, idx1 + 1, idx2 + 1, n1, n2, dp);
        }

        int opt1 = check(text1, text2, idx1 + 1, idx2, n1, n2, dp);
        int opt2 = check(text1, text2, idx1, idx2 + 1, n1, n2, dp);

        dp[idx1][idx2] = max(opt1, opt2);
        return dp[idx1][idx2];
    }
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return check(text1, text2, 0, 0, n1, n2, dp);
    }
};