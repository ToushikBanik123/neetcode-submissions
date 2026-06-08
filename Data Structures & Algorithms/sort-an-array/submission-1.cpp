class Solution {
public:
    void msort(vector<int>& nums, int s, int e) {
        if (s >= e) return;
        int m = s + (e - s) / 2;
        msort(nums, s, m);
        msort(nums, m + 1, e);
        vector<int> ans;
        int i = s;
        int j = m + 1;
        while (i <= m && j <= e) {
            if (nums[i] < nums[j]) {
                ans.push_back(nums[i]);
                i++;
            } else {
                ans.push_back(nums[j]);
                j++;
            }
        }
        while (i <= m) {
            ans.push_back(nums[i]);
            i++;
        }
        while (j <= e) {
            ans.push_back(nums[j]);
            j++;
        }
        int k = 0;
        while (s <= e) {
            nums[s] = ans[k];
            s++;
            k++;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        msort(nums, 0, nums.size() - 1);
        return nums;
    }
};