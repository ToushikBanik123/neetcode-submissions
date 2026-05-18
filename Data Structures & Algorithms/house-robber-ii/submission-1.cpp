class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        if(n == 0) return nums[0];

        // Case 1: Rob houses 0..n-1 (exclude last house at index n)
        int li1 = nums[n-1];
        int sli1 = 0;
        for(int i = n-2; i >= 0; i--){
            int temp = max(li1, nums[i]+sli1);
            sli1 = li1;
            li1 = temp;
        }
        int ans1 = li1;

        // Case 2: Rob houses 1..n (exclude first house at index 0)
        int li2 = nums[n];
        int sli2 = 0;
        for(int i = n-1; i >= 1; i--){
            int temp = max(li2, nums[i]+sli2);
            sli2 = li2;
            li2 = temp;
        }
        int ans2 = li2;

        return max(ans1,ans2);
    }
};