// class Solution {
// public:
//     vector<int> partitionLabels(string s) {

//         unordered_map<char,int> lasts;
//         int n=s.length();

//         for (int i = 0; i < n; i++) {

//             lasts[s[i]]=i;
             
//         }

//         int p=0;
//         int e=lasts[s[0]];
//         vector<int> ans;
    
       

//         for (int i = 0; i < n; i++) {

//             if(i==e){
//                 int answer=e-p+1;
//                 ans.push_back(answer);
                
//                 p=i+1;
//                    if (i + 1 < n) e = lasts[s[i + 1]];

//             }else{
//                  e=max(e,lasts[s[i]]);
//             }       
//         }

// return ans;
        
//     }
// };






class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {0}; 
        int n = s.size();


        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }


        vector<int> ans;
        int p = 0, e = 0;

        for (int i = 0; i < n; i++) {
            e = max(e, last[s[i] - 'a']);
            if (i == e) {              
                ans.push_back(e - p + 1);
                p = i + 1;            
            }
        }
        return ans;
    }
};