class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() -1;
        int li = nums[n];
        int sli = 0;
        for(int i = n-1; i >= 0; i--){
            int temp = max(li,nums[i]+sli);
            sli = li;
            li = temp;
        }   
        return max(li,sli);
    }
};
