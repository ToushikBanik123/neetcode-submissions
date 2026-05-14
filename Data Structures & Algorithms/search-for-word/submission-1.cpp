class Solution {
public:
    bool f(vector<vector<char>>& board, int i, int j, string& word, int index) {
        if (index >= word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size())
            return false;
        if (board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#';  // mark visited

        bool found = f(board, i+1, j, word, index+1) ||
                     f(board, i-1, j, word, index+1) ||
                     f(board, i, j+1, word, index+1) ||
                     f(board, i, j-1, word, index+1);

        board[i][j] = temp;  // restore
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (f(board, i, j, word, 0)) return true;
        return false;
    }
};