class Solution {
   public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& table) {
        int adj[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto x : adj) {
            int r = i + x[0];
            int c = j + x[1];

            if (0 <= r && 0 <= c && r < n && c < m && table[r][c] == 1) {
                table[r][c] = 0;
                dfs(r, c, n, m, table);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> table = grid;
        int n = table.size();
        int m = table[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && table[i][j] == 1) {
                    table[i][j] = 0;
                    dfs(i, j, n, m, table);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (table[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
