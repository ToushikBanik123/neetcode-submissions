class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1) return;

        int m = matrix.size();
        int n = matrix[0].size();

        int l = 1, r = 1, t = 1, b = 1;  // fix 2: all initialized to 1

        if (i > 0 && matrix[i-1][j] > matrix[i][j]) {  // fix 1: m not n
            dfs(i-1, j, dp, matrix);
            l = dp[i-1][j] + 1;
        }
        if (i < m - 1 && matrix[i+1][j] > matrix[i][j]) {  // fix 1: m not n
            dfs(i+1, j, dp, matrix);
            r = dp[i+1][j] + 1;
        }
        if (j > 0 && matrix[i][j-1] > matrix[i][j]) {
            dfs(i, j-1, dp, matrix);
            t = dp[i][j-1] + 1;
        }
        if (j < n - 1 && matrix[i][j+1] > matrix[i][j]) {  // fix 1: n not m
            dfs(i, j+1, dp, matrix);
            b = dp[i][j+1] + 1;
        }

        dp[i][j] = max({l, r, t, b});  // fix 3: valid max call, +1 moved above
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = INT_MIN;  // fix 4: renamed from max

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == -1) dfs(i, j, dp, matrix);
                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                }
            }
        }
        return ans;
    }
};