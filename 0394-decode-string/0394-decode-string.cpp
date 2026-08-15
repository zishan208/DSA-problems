class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                string temp = "";
               
                
                while (!st.empty() && st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                st.pop(); 

                reverse(temp.begin(), temp.end());

                
                int num = 0;
                int multiplier = 1;
                while (!st.empty() && isdigit(st.top())) {
                    num = num + (st.top() - '0') * multiplier;
                    multiplier *= 10;
                    st.pop();
                }

                string result = "";
                while (num--) {
                    result += temp;
                }

                int count = 0;
                while (count != result.length()) {
                    st.push(result[count]);
                    count++;
                }
            } else {
                st.push(s[i]);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};