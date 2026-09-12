class Solution {
    private:
    int factorial(int n){
        if(n==0) return 1;
    return n*factorial(n-1);
    }
    int c(int n, int i ){

        return factorial(n)/(factorial(i)*factorial(n-i));

    }
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;
        
        ans.push_back({1});



          for (int i = 1; i < numRows; i++) {
            vector<int> curr(i + 1, 1); 
            for (int j = 1; j < i; j++) {
                curr[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(curr);
        }
return ans;
        
    }
};