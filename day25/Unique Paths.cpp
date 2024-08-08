class Solution {
public:
    // int countPaths(int m, int n, int i, int j, vector<vector<int>>& dp){
    //     if(i == m || j == n) return 0;
    //     if(i == m-1 && j == n-1) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int right = countPaths(m, n, i, j+1,dp);
    //     int left = countPaths(m, n, i+1, j,dp);
    //     return dp[i][j] = left + right;
    // }
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // return countPaths(m, n, 0, 0, dp);
        int dp[m][n];
        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }
        for(int j = 0; j < m; j++){
            dp[j][0] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

        
    }
};