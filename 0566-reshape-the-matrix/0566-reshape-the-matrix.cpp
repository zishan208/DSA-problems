class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int ro=mat.size();
        int co=mat[0].size();
        int total=mat.size()*mat[0].size();
        if(ro*co!=r*c) return mat;
       
      vector<vector<int>> ans(r, vector<int>(c));
        for(int i=0;i<total;i++){

            ans[i / c][i % c]=mat[i / co] [i% co];



          
            
        }
        return ans;
    }
};