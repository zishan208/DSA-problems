class Solution {
public:
    bool isAnagram(string s, string t) {
        int result=0;
        

        // we find each word is mention in the string or not;

            if (s.size()!=t.size())
            {
                return false;
            }

            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            if (s==t)
            {
                return true;
            }
            return false;
            
            
        
    }
};