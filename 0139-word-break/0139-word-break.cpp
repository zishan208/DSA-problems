class Solution {
private:
    bool finds(const string& s, vector<string>& wordDict, int start, int end, vector<int>& memo) {
        if (start == s.length()) return true;
        if (end == s.length()) return false;

        if (memo[start] != -1) {
            return memo[start];
        }

        string temp = s.substr(start, end - start + 1);
        bool isWord = find(wordDict.begin(), wordDict.end(), temp) != wordDict.end();

        if (isWord) {
            if (finds(s, wordDict, end + 1, end + 1, memo)) {
                return memo[start] = true;
            }
        }

        bool result = finds(s, wordDict, start, end + 1, memo);
        return memo[start] = result;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.length(), -1); 
        return finds(s, wordDict, 0, 0, memo);
    }
};