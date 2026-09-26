class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for(int i = 0; i < knowledge.size(); i++){
            m[knowledge[i][0]] = knowledge[i][1];
        }


        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                string key = "";
                i++;
                while(s[i] != ')'){
                    key += s[i];
                    i++;
                }
                ans += (m.find(key) != m.end()) ? m[key] : "?";
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};