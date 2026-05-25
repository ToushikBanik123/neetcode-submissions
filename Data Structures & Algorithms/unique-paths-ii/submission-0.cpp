class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n = og[0].size();
        if (og[0][0] == 1 || og[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                if (og[i][j] == 1) continue;
                long long val1 = 0;
                long long val2 = 0;
                if (j + 1 < n) val1 = dp[i][j + 1];
                if (i + 1 < m) val2 = dp[i + 1][j];
                dp[i][j] = val1 + val2;
            }
        }
        return (int)dp[0][0];
    }
};