class Solution {
   public:
    void f(vector<int> nums, int t, int sum, vector<int> sumArr, vector<vector<int>>& ans, int i) {
        if (nums.size() <= i || t < sum) return;
        if (t == sum) {
            ans.push_back(sumArr);
            return;
        }
        sumArr.push_back(nums[i]);
        f(nums, t, sum + nums[i], sumArr, ans, i);
        sumArr.pop_back();
        f(nums, t, sum, sumArr, ans, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        f(nums, target, 0, {}, ans, 0);
        return ans;
    }
};