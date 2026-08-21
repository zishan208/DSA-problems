class Solution {
private:
    void check(int n, int count_, int _count, string temp, vector<string>& ans) {
        if (count_ > n || _count > n) return;

        if (count_ == n && _count == n) {
         
                ans.push_back(temp);
         return;
        }

        if (count_ < n) {
   check(n, count_ + 1, _count, temp + '(', ans);
        }
        if (_count < count_) {
            check(n, count_, _count + 1, temp + ')', ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        vector<string> ans;
        check(n, 0, 0, "", ans);
        return ans;
    }
};