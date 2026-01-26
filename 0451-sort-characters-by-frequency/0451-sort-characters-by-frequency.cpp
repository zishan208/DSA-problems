class Solution {
public:
    string frequencySort(string s) {
        int count[62] = {0};

        // Count frequencies
        for (char c : s) {
            if (c >= 'A' && c <= 'Z')
                count[c - 'A']++;
            else if (c >= 'a' && c <= 'z')
                count[26 + (c - 'a')]++;
            else if (c >= '0' && c <= '9')
                count[52 + (c - '0')]++;
        }

        // Collect into vector for sorting
        vector<pair<int,int>> freq;
        for (int i = 0; i < 62; i++) {
            if (count[i] > 0) freq.push_back({count[i], i});
        }

        // Sort by frequency descending
        sort(freq.begin(), freq.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        // Build result string
        string result;
        for (auto &p : freq) {
            int f = p.first, idx = p.second;
            char ch;
            if (idx < 26) ch = 'A' + idx;
            else if (idx < 52) ch = 'a' + (idx - 26);
            else ch = '0' + (idx - 52);
            result.append(f, ch);
        }

        return result;
    }
};