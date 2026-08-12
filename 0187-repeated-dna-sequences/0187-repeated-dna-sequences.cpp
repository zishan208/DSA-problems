class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        string temp="";
        vector<string> ans;
         if (s.length() < 10) return ans; 
        unordered_map<string,int> count;

        for (int i = 0; i <s.length(); i++) {
           string sub = s.substr(i, 10);
           ++count[sub];
           if (count[sub]==2) {
           ans.push_back(sub); 
           }

                  
        }
return ans;
    }
};