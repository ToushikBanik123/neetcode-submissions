class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> LIS(n,1);

        for(int i = n-1; 0 <= i; i--){
            int ans = 1;
            for(int j = i+1; j < n; j++){
                if(nums[i] < nums[j]){
                    ans = max(ans,1+LIS[j]);
                }
            }
            LIS[i] = ans;
        }
        return *max_element(LIS.begin(), LIS.end());
    }
};
