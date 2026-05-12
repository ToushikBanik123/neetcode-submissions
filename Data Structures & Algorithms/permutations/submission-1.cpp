class Solution {
public:
    void f(vector<int> &x, int index, vector<vector<int>> & ans){
        int n = x.size();
        for(int i = 0; i < n+1; i++){
            vector<int> temp;
            for(int j = 0; j < i; j++){
                temp.push_back(x[j]);
            }
            temp.push_back(index);
            for(int j = i; j < n; j++){
                temp.push_back(x[j]);
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> permuteHelper(vector<int>& nums, int i){
        if(nums.size() <= i) return {{}};
        vector<vector<int>> val = permuteHelper(nums,i+1);
        vector<vector<int>> ans;
        for(auto x: val){
            f(x,nums[i],ans);
        }
        return ans;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return permuteHelper(nums,0);
    }
};
