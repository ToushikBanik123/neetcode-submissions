class Solution {
   public:
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<int> dp(m + 1, 0);

        for (int j = 0; j <= m; j++) dp[j] = m - j;

        for (int i = n - 1; i >= 0; i--) {
            vector<int> dptemp(m + 1, 0);
            dptemp[m] = n - i;

            for (int j = m - 1; j >= 0; j--) {
                if (w1[i] == w2[j]) {
                    dptemp[j] = dp[j + 1];
                } else {
                    dptemp[j] = 1 + min({dp[j + 1], dp[j], dptemp[j + 1]});
                }
            }
            dp = dptemp;
        }
        return dp[0];
    }
};
