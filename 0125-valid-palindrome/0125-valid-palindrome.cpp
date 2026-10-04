class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            // Skip non-alphanumeric from left
            while (i < j && !isalnum(s[i])) i++;
            // Skip non-alphanumeric from right
            while (i < j && !isalnum(s[j])) j--;

            // Compare case-insensitively
            if (tolower(s[i]) != tolower(s[j])) return false;

            i++;
            j--;
        }
        return true;
    }
};