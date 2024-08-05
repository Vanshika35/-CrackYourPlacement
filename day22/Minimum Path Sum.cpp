class Solution {
public:
    int countMinPath(int m, int n, int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1) return grid[i][j];
        if(i == m || j == n) return 1000000;
        if(dp[i][j] != -1) return dp[i][j];
        int bottom = grid[i][j] + countMinPath(m, n, i+1, j, grid,dp);
        int right = grid[i][j] + countMinPath(m, n, i, j+1, grid,dp);
        return dp[i][j] = min(bottom, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return countMinPath(m,n,0,0,grid,dp);
    }
};