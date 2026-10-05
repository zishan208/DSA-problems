class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;

        for (char &c : s) {
            if (c == '(') {
                st.push(-1); 
            } else {
                if (st.top() == -1) {
                    st.pop();
                    st.push(1);
                } else {
                    int total = 0;
                    while (st.top() != -1) {
                        total += st.top();
                        st.pop();
                    }
                    st.pop(); 
                    st.push(total * 2);
                }
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};