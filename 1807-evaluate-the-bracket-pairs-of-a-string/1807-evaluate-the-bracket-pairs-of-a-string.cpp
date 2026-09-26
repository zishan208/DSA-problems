class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for (const auto& kv : knowledge) {
      m[kv[0]] = kv[1];
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


// class Solution {
// public:
//     string evaluate(string s, vector<vector<string>>& knowledge) {
//         unordered_map<string, string> m;
//         for (const auto& kv : knowledge) {
//             m[kv[0]] = kv[1];
//         }

//         string ans;
//         string key;
//         for (char c : s) {
//             if (c == '(') {
//                 ans += key;
//                 key.clear();
//             } else if (c == ')') {
//                 ans += (m.count(key) ? m[key] : "?");
//                 key.clear();
//             } else {
//                 key += c;
//             }
//         }
//         ans += key;
//         return ans;
//     }
// };