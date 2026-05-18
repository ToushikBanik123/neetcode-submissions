class Solution {
public:
    map<int,int> m;
    int f(int i, vector<int>& nums){
        if(nums.size() <= i) return 0;
        if(m.find(i) != m.end()) return m[i];
        return m[i] = max(f(i+1,nums),nums[i]+f(i+2,nums));
    }
    int rob(vector<int>& nums) {
        return f(0,nums);
    }
};
