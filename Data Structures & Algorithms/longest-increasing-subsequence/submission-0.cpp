class Solution {
public:
    map <pair<int,int>,int> mp;

    int f(int i, vector<int>& nums, int lastVal) {
        if (i >= nums.size())
            return 0;

        if(mp.find({i,lastVal}) != mp.end()) return mp[{i,lastVal}];
        int skip = f(i + 1, nums, lastVal);

        int include = 0;
        if (lastVal < nums[i])
            include = 1 + f(i + 1, nums, nums[i]);

        return mp[{i,lastVal}] = max(skip, include);
    }
    int lengthOfLIS(vector<int>& nums) { return f(0, nums, INT_MIN); }
};