




class Solution {
    static bool cmp(pair<char,int> &a, pair<char,int> &b) {
        return a.second > b.second; 
    }
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        for (char &c : s) {
            int index = c - 'a';
            count[index]++;
        }

        vector<pair<char,int>> c;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                int n = count[i];
                char ch = 'a' + i;
                c.push_back({ch, n});
            }
        }

        sort(c.begin(), c.end(), cmp);

        int size = c.size();
        int idx = 0;
        string ans = s; 

        for (int i = 0; i < size; i++) {
            while (c[i].second > 0) {
                if (idx >= s.size()) idx = 1;
                ans[idx] = c[i].first;
                c[i].second--;
                idx += 2;
            }
        }
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] == ans[i-1]) return "";
        }
        return ans;
    }
};