class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxdp(n + 1, 1);
        vector<int> mindp(n + 1, 1);
        for (int i = n - 1; i >= 0; i--) {
            maxdp[i] = max(nums[i], max(maxdp[i + 1] * nums[i],mindp[i + 1] * nums[i]));
            mindp[i] = min(nums[i], min(maxdp[i + 1] * nums[i], mindp[i + 1] * nums[i]));
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, maxdp[i]);
        }
        return ans;
    }
};
