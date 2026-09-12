class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> maxi(n);        
        int temp = prices[n - 1];  

        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] > temp) {
                temp = prices[i];
            }
            maxi[i] = temp;   
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, maxi[i] - prices[i]);
        }

        return ans;
    }
};