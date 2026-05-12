class Solution {
public:
    void f(vector<int> &nums, int i, vector<int> val, vector<vector<int>> & ans){
        if(i >= nums.size()){
            ans.push_back(val);
            return;
        }
        val.push_back(nums[i]);
        f(nums,i+1,val,ans);
        val.pop_back();
        int temp = nums[i];
        while(i <= nums.size() && nums[i] == temp){
            i++;
        }
        f(nums,i,val,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        f(nums,0,{},ans);
        return ans;
    }
};
