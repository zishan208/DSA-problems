class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
         int rows = mat.size();
        int cols = mat[0].size();
        int count=rows*cols;
       
        
        vector<vector<int>>  ans(rows+cols-1);


        for(int i=0;i<count;i++){


            int r = i / cols;     
         int c = i % cols;    
            int diagIdx = r + c;   

            ans[diagIdx].push_back(mat[r][c]);
            
        }
        vector<int> fans;

        for(int i=0;i<ans.size();i++){
            if(i%2==0){
                reverse(ans[i].begin(),ans[i].end());
            }
            fans.insert(fans.end(),ans[i].begin(),ans[i].end());
            ans[i].clear();
        }
     return fans;   
    }
};