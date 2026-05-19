class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1) return n;
        if(n == 2) return 1;
        int T1 = 0;
        int T2 = 1;
        int T3 = 1;
        for(int i = 3; i <= n; i++){
            int ans = T1 + T2 + T3;
            T1 = T2;
            T2 = T3;
            T3 = ans;
        }
        return T3;
    }
};