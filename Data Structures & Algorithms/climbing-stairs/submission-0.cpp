class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;

        int fval = 1; 
        int sval = 2; 
        int ans = 0;
        for(int i = 3; i <= n; i++){
            ans = sval + fval; 
            fval = sval;
            sval = ans;
        }
        return ans;
    }
};
