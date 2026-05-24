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
            for (int i = target; i >= 0; i--) {
                if (dp[i] && i + x <= target) {
                    dp[i + x] = 1;
                }
            }
        }
        return dp[target];
    }
};
