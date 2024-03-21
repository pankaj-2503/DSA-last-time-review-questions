class Solution {
public:    
    int findLowestCoins(vector<int> &coins, int cur, int amount) {
        if (cur >= coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;   
        
        int res = -1;
        if (coins[cur] > amount) {
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            res = doNotTakeCoin;
        }
        else {
            int takeCoin = 1 + findLowestCoins(coins, cur + 0, amount - coins[cur]);
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            res = min(takeCoin, doNotTakeCoin);
        }
        return res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int res = findLowestCoins(coins, 0, amount);
        return (res == INT_MAX - 1 ) ? -1 : res;
    }
};

class Solution {
public:    
    int dp[12 + 1][10000 + 1];
    
    int findLowestCoins(vector<int> &coins, int cur, int amount) {
        if (cur == coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;   
        
        if (dp[cur][amount] != -1)
            return dp[cur][amount];
        
        int res = -1;
        if (coins[cur] > amount) {
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            dp[cur][amount] = res = doNotTakeCoin;
        }
        else {
            int takeCoin = 1 + findLowestCoins(coins, cur + 0, amount - coins[cur]);
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            dp[cur][amount] = res = min(takeCoin, doNotTakeCoin);
        }
        return dp[cur][amount] = res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = findLowestCoins(coins, 0, amount);
        return (res == INT_MAX - 1 ) ? -1 : res;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);  // Initialize with INT_MAX as we need minimum
        dp[0] = 0;  // 0 coins needed to make up 0 amount

        // Iterate through amounts from 1 to the target amount
        for (int i = 1; i <= amount; i++) {
            // Iterate through available coin denominations
            for (int j = 0; j < n; j++) {
                // Check if the current coin can contribute to making up the amount i
                if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                    // Update dp[i] with the minimum number of coins
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // Return the final result, -1 if not possible to make up the amount
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};