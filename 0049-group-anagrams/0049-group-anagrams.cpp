
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<unordered_map<char,int>> wlc;
          vector<bool> used(strs.size(), false);

        //we have frequencies letter of each word

        for (int i = 0; i < strs.size(); i++)
        {
            unordered_map<char,int> map;


            for ( char c:strs[i])
            {
                char key=c;
                map[key]++;

            }
            wlc.push_back(map);

            

        }

        //now compare how many same and push in answer
        
        
        for (int i = 0; i < strs.size(); i++) {
            if (used[i]) continue; // skip if already grouped
            vector<string> group;
            group.push_back(strs[i]);
            used[i] = true;

            for (int j = i + 1; j < strs.size(); j++) {
                if (!used[j] && wlc[i] == wlc[j]) { // unordered_map supports ==
                    group.push_back(strs[j]);
                    used[j] = true;
                }
            }

            ans.push_back(group);
        }

        
        


return ans;
        
    }
};