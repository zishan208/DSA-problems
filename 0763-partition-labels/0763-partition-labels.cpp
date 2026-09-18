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
        int last[26] = {0}; // har character ka last index
        int n = s.size();

        // Har character ka last occurrence store karo
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0, end = 0;

        for (int i = 0; i < n; i++) {
            end = max(end, last[s[i] - 'a']); // current partition ka end expand karo
            if (i == end) {                   // partition complete
                ans.push_back(end - start + 1);
                start = i + 1;                // next partition start
            }
        }
        return ans;
    }
};