class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>> &visited,
             vector<vector<char>> &grid) {
        visited[i][j] = 1;
        int adj[4][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0}};
        for (auto x : adj) {
            int r = i + x[0];
            int c = j + x[1];
            if (0 <= r && 0 <= c && r < grid.size() && c < grid[0].size() &&
                grid[r][c] == '1' && !visited[r][c]) {
                dfs(r, c, visited, grid);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};