class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i = 0; i < nums.size(); i++){
            int index = nums[i];
            vector<vector<int>> temp;
            for(auto val : ans){
                val.push_back(index);
                temp.push_back(val);
            }
            for(auto val : temp){
                ans.push_back(val);
            } 
        }
        return ans;
    }
};
