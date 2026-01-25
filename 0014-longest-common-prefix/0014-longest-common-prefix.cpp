class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

         if (strs.empty()) return "";


        int min=200;
        string result;

        for (int i = 0; i < strs.size(); i++)
        {
            /* code */
            if (strs[i].size()<min)
            {
                min=strs[i].size();
            }
        }

        for (int i = 0; i < min; i++)
        {
            for (int j = 0; j < strs.size()-1; j++)
            {
                if (strs[j][i]!=strs[j+1][i])
                {
                         return result;   

                }

                
                
            }
            result.push_back(strs[0][i]);
            
        }  
        return result;      
    };
};