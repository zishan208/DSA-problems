// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if (n == 0) return 0;

//         vector<int> maxi(n);        
//         int temp = prices[n - 1];  

//         for (int i = n - 1; i >= 0; i--) {
//             if (prices[i] > temp) {
//                 temp = prices[i];
//             }
//             maxi[i] = temp;   
//         }

//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             ans = max(ans, maxi[i] - prices[i]);
//         }

//         return ans;
//     }
// };




// class Solution {
//     private:
//     void fs(vector<int>& prices,int index,int &maxi){
//         if(index<0) return 0;
   
//         maxi=max(maxi,prices[index]-maxi);
//         fd(prices,index--,maxi);

    
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if (n == 0) return 0;

//        int maxi=0;
//        fs(prices,index,maxi);
//        return maxi;   
//     }
// };


class Solution {
private:
    void fs(vector<int>& prices, int index, int& minPrice, int& maxProfit) {
        if (index == prices.size()) return;

        if (prices[index] < minPrice) {
            minPrice = prices[index];
        } else {
            maxProfit = max(maxProfit, prices[index] - minPrice);
        }

        fs(prices, index + 1, minPrice, maxProfit);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int minPrice = INT_MAX;
        int maxProfit = 0;

        fs(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};