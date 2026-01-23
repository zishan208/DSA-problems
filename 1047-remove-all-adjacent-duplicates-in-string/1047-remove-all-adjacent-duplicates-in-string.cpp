// class Solution {



// private:

// bool findAdjacent(string s){
//     for(int i = 0; i < s.length()-1;i++){
    
//         if (s[i]==s[i+1])
//         {
//             return true;
        
           
//         }
        
//     }
//     return false;
    
// }
// public:



//     string removeDuplicates(string s) {
//         while(findAdjacent(s)){

//              for(int i = 0; i < s.length()-1;i++){
    
//         if (s[i]==s[i+1])
//         {
//            s.erase(i,2);
//             if (i >= 2) i -= 2; // 
//                     else i = -1;  
           
//         }
        
//     }


          
          
            
//         }
// return s;
        
//     }
// };


class Solution {
    public:

string removeDuplicates(string s) {
    string result;
    for (char c : s) {
        if (!result.empty() && result.back() == c) {
            result.pop_back();  // remove duplicate
        } else {
            result.push_back(c);
        }
    }
    return result;
}

};






