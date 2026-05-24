class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) return 0;
        int target = sum / 2;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (auto x : nums) {
            vector<int> dptemp = dp;
            for (int i = 0; i <= target; i++) {
                if (dp[i] && i + x <= target) {
                    dptemp[i + x] = 1;
                }
            }
            dp = dptemp;
        }
        return dp[target];
    }
};
