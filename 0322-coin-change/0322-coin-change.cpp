class Solution {

    private:
    int solve(vector<int> &coins, int x, vector<int> &dp) {
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;      

    if (dp[x] != -1) return dp[x]; 

    int best = INT_MAX;
    
    for (int i = 0; i < coins.size(); i++) {
        int sub = solve(coins, x - coins[i], dp);
        if (sub != INT_MAX) {
            best = min(best, 1 + sub); 
        }
    }

    dp[x] = best;
    return dp[x];
}

    
public:
    int coinChange(vector<int>& coins, int amount) {

        if (amount == 0) return 0;

    vector<int> dp(amount + 1, -1);

    int ans = solve(coins, amount, dp);
    return (ans == INT_MAX) ? -1 : ans;
        
    }
};




