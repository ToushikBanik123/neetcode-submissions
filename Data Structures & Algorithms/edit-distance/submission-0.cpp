class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 0; i < n; i++) dp[i][m] = n - i;
        for(int j = 0; j < m; j++) dp[n][j] = m -j;

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(w1[i] == w2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    dp[i][j] = 1 + min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
                }
            }
        }
        return dp[0][0];
    }
};
