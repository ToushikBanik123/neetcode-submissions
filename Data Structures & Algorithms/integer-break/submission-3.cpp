class Solution {
public:
    map <int,int> mp;

    int integerBreak(int n) {
        if(n == 1) return 1;
        if(mp.find(n) != mp.end()) return mp[n];

        int ans = 1;
        for(int i = 1; i < n ; i++){
            ans = max(ans,max(integerBreak(n-i)*i,(n-i)*i));
        }
        return mp[n] = ans;
    }
};