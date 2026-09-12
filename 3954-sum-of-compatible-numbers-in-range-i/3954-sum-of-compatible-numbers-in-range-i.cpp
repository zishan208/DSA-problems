class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        int start = n - k;
        if (start < 1) start = 1;
        int end = n + k;
        for (int x = start; x <= end; ++x) {
            if ((n & x) == 0) ans += x;
        }
        return ans;
    }
};