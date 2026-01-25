class Solution {
public:
    string reverseWords(string s) {
        vector<string> copy;
        int k = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (i > k) { // avoid empty substrings
                    copy.push_back(s.substr(k, i - k));
                }
                k = i + 1;
            }
        }

        // Add the last word
        if (k < s.size()) {
            copy.push_back(s.substr(k));
        }

        // Reverse the vector
        reverse(copy.begin(), copy.end());

        // Join words into a single string
        string result;
        for (int i = 0; i < copy.size(); i++) {
            result += copy[i];
            if (i != copy.size() - 1) result += " ";
        }

        return result;
    }
};