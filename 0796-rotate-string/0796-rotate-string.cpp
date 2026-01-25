class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size()!=goal.size()) return false;

  // total size-1 rotaion require to confirm ..

  for (int  i = 0; i < s.size(); i++)
  {
   if (s==goal)
   {
    return true;
   }

   char last=s[s.size()-1];
   s.erase(s.size()-1);
   s.insert(s.begin(),last);
  }
        return false;
    }
};