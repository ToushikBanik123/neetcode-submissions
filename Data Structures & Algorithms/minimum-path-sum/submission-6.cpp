class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp = grid[m - 1];
        for (int j = n - 2; j >= 0; j--) {
            dp[j] += dp[j+1];
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if(j == n-1){
                    dp[j] += grid[i][j];
                }else{
                    dp[j] = grid[i][j] + min(dp[j],dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};