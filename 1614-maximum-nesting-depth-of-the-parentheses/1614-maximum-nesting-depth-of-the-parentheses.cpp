class Solution {
public:
    int maxDepth(string s) {
        int left_b=0;
      
        int ans=0;
        

        for(char &c: s){
            if(c=='('){
                left_b++;
            }else if(c==')'){

                ans=max(ans,left_b);
                left_b--;


            }
        }
        return ans;
        
    }
};