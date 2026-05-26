class Solution {
   public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t2.size();
        int m = t1.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (t1[i] == t2[j]) {
                    // match: consume both characters
                    int diag = (i + 1 < m && j + 1 < n) ? dp[i + 1][j + 1] : 0;
                    dp[i][j] = 1 + diag;
                } else {
                    // no match: skip one character from either string
                    int val1 = (i + 1 < m) ? dp[i + 1][j] : 0;
                    int val2 = (j + 1 < n) ? dp[i][j + 1] : 0;
                    dp[i][j] = max(val1, val2);
                }
            }
        }
        return dp[0][0];
    }
};
