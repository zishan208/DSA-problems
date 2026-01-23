class Solution {
private:
    bool checkequal(int arr1[26], int arr2[26]) {
        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int arr1[26] = {0};
        int arr2[26] = {0};

        // Count frequency of s1
        for (char c : s1) {
            arr1[c - 'a']++;
        }

        int window = s1.length();

        // First window
        for (int i = 0; i < window; i++) {
            arr2[s2[i] - 'a']++;
        }
        if (checkequal(arr1, arr2)) return true;

        // Sliding window
        for (int i = window; i < s2.length(); i++) {
            int newChar = s2[i] - 'a';
            arr2[newChar]++;
            int oldChar = s2[i - window] - 'a';
            arr2[oldChar]--;

            if (checkequal(arr1, arr2)) return true;
        }

        return false;
    }
};