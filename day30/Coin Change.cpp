class Solution {
public:
    int minCount(int n, vector<int>& coins, int amount,  vector<vector<int>>& dp){
        if(n == 0){
            if(amount%coins[0]== 0){
                return amount/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(dp[n][amount] != -1) return dp[n][amount];
        int I = 1e9;
        if(coins[n] <= amount){
            I = 1 + minCount(n, coins, amount-coins[n], dp);
        }
        int E = minCount(n-1, coins, amount, dp);
        return dp[n][amount] = min(I,E);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        // int ans = minCount(n-1, coins, amount, dp);
        // return (ans == 1e9) ? -1 : ans;
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i = 0; i <= amount; i++){
            if(i%coins[0] == 0){
                dp[0][i] = i/coins[0];
            }else{
                dp[0][i] = 1e9;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount; j++){
                int I = 1e9;
                if(coins[i] <= j){
                    I = 1 + dp[i][j-coins[i]];
                }
                int E = dp[i-1][j];
                dp[i][j] = min(I,E);
            }
        }
        return (dp[n-1][amount] == 1e9) ? -1 : dp[n-1][amount];
    }
};