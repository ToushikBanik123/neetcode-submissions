class Solution {
public:
    int nums(string &s, int i, int j){
        int ans = s[i] -'0';
        if(j){
            ans *= 10;
            ans += s[i+1] -'0';
        }
        return ans;
    }

    int f(string &s, int i,vector<int> &mp){
        if(s.length() <= i) return 1;
        if(mp[i] != -1) return mp[i];

        int ans = 0;
        if(0 <nums(s,i,0) && nums(s,i,0) <= 9){
            ans += f(s,i+1,mp);
        }
        if(i+1 < s.length()){
            if(9 < nums(s,i,1) && nums(s,i,1) <= 26){
                ans += f(s,i+2,mp);
            }
        }
        return mp[i] = ans;
    }

    int numDecodings(string s) {
        vector<int> mp(s.length(),-1);
        return f(s,0,mp);
    }
};
