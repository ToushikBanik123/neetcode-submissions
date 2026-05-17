class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        map<int,int> s;
        int n = cost.size();
        s[n-1] = cost[n-1];
        s[n-2] = cost[n-2];
        for(int i = n-2; i >= 0; i--){
            s[i] = cost[i] + min(s[i+1],s[i+2]);
        }
        return min(s[0],s[1]);
    }
};
