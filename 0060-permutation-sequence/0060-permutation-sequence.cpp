

class Solution {
    private:
    // factorial calcu;ation

    int fact(int x){
        if (x==0 || x==1) return 1;
        return x*fact(x-1);
        
    }
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        for (int i =1; i <= n; i++)
        {
            arr.push_back(i);
        };
        //123456789 == n could be anything -----------
        string required="";
        for (int i = n; i>=1; i--)
        {
            int factorial=fact(i-1);
            int element_index=k/factorial;
            k=k-fact(i-1)*element_index;
            required=required+to_string(arr[element_index]);
            arr.erase(arr.begin()+element_index);
            // k=k%factorial;
        }
        
        return required;

      
        
    }
};