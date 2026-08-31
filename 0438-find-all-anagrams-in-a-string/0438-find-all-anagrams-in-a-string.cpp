

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int len1=s.length();
//         int len2=p.length();
        
//         sort(p.begin(),p.end());
//         vector<int> ans;
//         if(len1<len2) return ans;

//         for(int i=0;i<len1-len2+1;i++){
//             string temp=s.substr(i,len2);
//             sort(temp.begin(),temp.end());
//             if(temp==p){
//                 ans.push_back(i);
//             }




//         }
//         return ans;


        
//     }
// };




class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len1=s.length();
        int len2=p.length();
        
      
        vector<int> ans;
        if(len1<len2) return ans;
        vector<int> pc(26,0);
        for(char c: p){
            int index=c-'a';
            pc[index]++;
        }
        vector<int> temp(26,0);
         for(int i=0;i<len2;i++){
            int index=s[i]-'a';
         temp[index]++;
        }

        if (pc == temp) ans.push_back(0);

        for (int i = len2; i < len1; i++) {
         temp[s[i] - 'a']++;
            temp[s[i - len2] - 'a']--;

            if (temp== pc) {
                ans.push_back(i - len2 + 1);
            }
        }


        
        return ans;


        
    }
};
