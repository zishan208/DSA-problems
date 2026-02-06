class Solution {
    private:
    bool find(int n){
            if(n==1) return true;
            if (n%4!=0 || n==0) return false;
            
          return  find(n/4);
        
        
    }
public:
    bool isPowerOfThree(int n) {
        if(n<0) return false;
       return find(n);

        
    }
};