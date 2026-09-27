class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {


            if (s[i] == '(') {
                st.push(i);

            } else if (s[i] == ')') {

                int left_b = st.top();
                st.pop();
            reverse(s.begin() + left_b + 1, s.begin() + i);
                s.erase(s.begin() + i);
                s.erase(s.begin() + left_b);
                i = i - 2; 
            }
        }
        return s;
    }
};