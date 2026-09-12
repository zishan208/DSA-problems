class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        int start = n - k;
        if (start < 1) start = 1;
       
        for (int x = start; x <= n+k; ++x) {
            if ((n & x) == 0) ans += x;
        }
        return ans;
    }
};