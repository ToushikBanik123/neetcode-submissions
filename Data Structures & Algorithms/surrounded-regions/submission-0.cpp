class Solution {
   public:
    void dfs(int i, int j, vector<vector<char>>& board) {
        int adj[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto x : adj) {
            int r = i + x[0];
            int c = j + x[1];
            if (0 <= r && 0 <= c && r < board.size() && c < board[0].size() && board[r][c] == 'O'){
                board[r][c] = 'M';
                dfs(r,c,board);
            } 
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O') {
                    board[i][j] = 'M';
                    dfs(i, j, board);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'M') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
