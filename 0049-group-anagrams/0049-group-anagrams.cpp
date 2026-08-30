class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {



        unordered_map<string,vector<string>> um;

        for(string s: strs){
            string temp=s;
            sort(temp.begin(),temp.end());
            um[temp].push_back(s);

        }
          vector<vector<string>> ans;

        for(auto it: um){
            
            ans.push_back(it.second);

        }


        return ans;
        
    }
};














