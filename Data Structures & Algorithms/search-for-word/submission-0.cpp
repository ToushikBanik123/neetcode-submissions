class Solution {
   public:
    bool f(vector<vector<char>>& board, int i, int j, string& word, int index,
           set<pair<int, int>>& path) {
        if (index >= word.size()) return 1;
        if (i < 0 || j < 0 || i >= (int)board.size() || j >= (int)board[i].size() ||
            path.find({i, j}) != path.end() || board[i][j] != word[index]) {
            return 0;
        }
        path.insert({i, j});
        if (f(board, i + 1, j, word, index + 1, path) ||
            f(board, i - 1, j, word, index + 1, path) ||
            f(board, i, j + 1, word, index + 1, path) ||
            f(board, i, j - 1, word, index + 1, path)) {
            path.erase({i, j});
            return 1;
        }
        path.erase({i, j});
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                set<pair<int, int>> path;
                if (f(board, i, j, word, 0, path)) {
                    return 1;
                }
            }
        }
        return 0;
    }
};
