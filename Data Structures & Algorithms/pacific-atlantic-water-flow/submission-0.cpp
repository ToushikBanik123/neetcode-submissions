class Solution {
   public:
    void dfs(int i, int j, vector<vector<bool>>& dp, vector<vector<int>>& heights) {
        int adj[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto x : adj) {
            int r = x[0] + i;
            int c = x[1] + j;
            if (0 <= r && 0 <= c && r < dp.size() && c < dp[0].size() &&
                (heights[r][c] >= heights[i][j]) && dp[r][c] == 0) {
                    dp[r][c] = 1;
                    dfs(r,c,dp,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pdp(n, vector<bool>(m, 0));
        vector<vector<bool>> adp(n, vector<bool>(m, 0));
        vector<vector<int>> ans;

        for (int j = 0; j < m; j++) {
            if (pdp[0][j] == 0) {
                pdp[0][j] = 1;
                dfs(0, j, pdp, heights);
            }
            if (adp[n - 1][j] == 0) {
                adp[n - 1][j] = 1;
                dfs(n - 1, j, adp, heights);
            }
        }
        for (int i = 0; i < n; i++) {
            if (pdp[i][0] == 0) {
                pdp[i][0] = 1;
                dfs(i, 0, pdp, heights);
            }
            if (adp[i][m - 1] == 0) {
                adp[i][m - 1] = 1;
                dfs(i, m - 1, adp, heights);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (adp[i][j] == 1 && pdp[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
