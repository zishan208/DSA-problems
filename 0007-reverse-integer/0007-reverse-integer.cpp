class Solution {
public:
    int reverse(int x) {

        long long n=0;
        while (x!=0)
        {
         int  temp=x%10;
          n=n*10+temp;
          x/=10;

        }
        if(n<INT_MIN  || n>INT_MAX ) return 0;
        
   return (int)n;     
    }
};