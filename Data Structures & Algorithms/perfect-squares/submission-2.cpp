class Solution {
   public:
    map<int, int> mp;

    int f(int n) {
        if (n == 0) return 0;
        if (mp.find(n) != mp.end()) return mp[n];

        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int sub = f(n - (i * i));
            ans = min(1 + sub, ans);
        }
        return mp[n] = ans;
    }
    int numSquares(int n) { return f(n); }
};