class Solution {
private:
    void check(int n, int count_, int _count, string temp, vector<string>& ans) {
        if (count_ > n || _count > n) return;

        if (count_ == n && _count == n) {
          stack<char> st;

         
            for (int i = 0; i < temp.length(); i++) {
                if (temp[i] == '(') {
          st.push(temp[i]);
                } else { 
                  
                    if (st.empty() || st.top() != '(') {
                        return;
                } else {
                        st.pop();
                    }
                }
            }

            if (st.empty()) {
                ans.push_back(temp);
            }
            return;
        }

        if (count_ < n) {
   check(n, count_ + 1, _count, temp + '(', ans);
        }
        if (_count < n) {
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