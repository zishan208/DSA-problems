class Solution {
    private:
     int reverse(int x) {

        long long n=0L;
        while (x!=0)
        {
          int temp=x%10;
          n=n*10+temp;
          x/=10;

        }
        return n;
        
    }
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int rev=reverse(x);
        return rev==x;
    }

};