class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0; 
        int e = numbers.size()-1;
        while(s<=e){
            int ans = numbers[s]+numbers[e];
            if(ans == target){
                return {s+1,e+1};
            }else if(ans < target){
                s++;
            }else{
                e--;
            }
        }
        return {-1,-1};
    }
};
