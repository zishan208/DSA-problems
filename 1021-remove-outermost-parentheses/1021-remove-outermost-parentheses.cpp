class Solution {
public:
    string removeOuterParentheses(string s) {
        int size = s.length(); 
        stack<char> st;
        string ans = "";     

        for (int i = 0; i < size; i++) {
            char c = s[i];

            if (c == '(') {
                if (!st.empty()) ans.push_back(c);
                st.push(c);
            } 
            else { 
                st.pop();
                if (!st.empty()) ans.push_back(c);
            }
        }
        return ans;
    }
};