class Solution {
public:
    map<pair<int,int>,int> mp;

    int f(vector<int>& coins, int i,int k){
        if(k == 0) return 0;
        if(mp.find({i,k}) != mp.end()) return mp[{i,k}];
        if(k < 0 || i >= coins.size()) return -1;
        int ans = INT_MAX;
        int val1 = f(coins,i+1,k);
        int val2 = f(coins,i,k-coins[i]);
        if(val1 != -1){
            ans = min(val1,ans);
        }
        if(val2 != -1){
            ans = min(val2+1,ans);
        }
        return mp[{i,k}] = ans == INT_MAX? -1 : ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        return f(coins,0,amount);
    }
};
