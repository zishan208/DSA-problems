class Solution {
    private:
    void com(vector<int> curr,vector<vector<int>>& ans,int &n,int &k,int start){

        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }

        for(int i=start;i<=n;i++){

            
                    
                curr.push_back(i);
       
                com(curr,ans,n,k,i+1);
                curr.pop_back();
            
                    
                
     



        }
       
        
       


    }
public:
    vector<vector<int>> combine(int n, int k) {


        vector<int> curr;
        vector<vector<int>> ans;


          

        com(curr,ans,n,k,1);

        return ans;


        
    }
};