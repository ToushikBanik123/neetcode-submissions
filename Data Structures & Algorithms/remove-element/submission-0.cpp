class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans(nums.size());
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                ans[j] = nums[i];
                j++;
            }
        }
        nums = ans;
        return j;
    }
};