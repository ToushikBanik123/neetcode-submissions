class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int,int> element = {0,0};
        for(int i = 0; i < nums.size(); i++){
            if(element.second == 0){
                element.first = nums[i];
                element.second++;
            }
            if(element.first == nums[i]){
                element.second++;
            }else{
                element.second--;
            }
        }
        return element.first;
    }
};