class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> dp;
        for(int i = 0; i < m; i++){
            vector<long long> temp;
            for(int j = 0; j < n; j++){
                temp.push_back(grid[i][j]);
            }
            dp.push_back(temp);
        }
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1) continue;
                int val1 = INT_MAX;
                int val2 = INT_MAX;
                if(j+1 < n) val1 = dp[i][j+1];
                if(i+1 < m) val2 = dp[i+1][j];
                dp[i][j] += min(val1,val2);
            }
        }
        return dp[0][0];
    }
};