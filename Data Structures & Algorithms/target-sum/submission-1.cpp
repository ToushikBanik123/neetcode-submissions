class Solution {
   public:
    map<pair<int, int>, int> mp;

    int f(vector<int>& nums, int i, int target) {
        if (i >= nums.size()) return target ? 0 : 1;
        if (mp.find({i, target}) != mp.end()) return mp[{i, target}];

        return mp[{i, target}] =
                   f(nums, i + 1, target - nums[i]) + f(nums, i + 1, target + nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) { return f(nums, 0, target); }
};
