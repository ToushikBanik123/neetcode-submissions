class Solution {
public:
    map<pair<int,int>,int> mp;

    int f(vector<int>& coins, int i, int amount){
        if(i >= coins.size() || amount < 0) return 0;
        if(amount == 0) return 1;
        if(mp.find({i,amount}) != mp.end()) return mp[{i,amount}];
        return mp[{i,amount}] = f(coins,i+1,amount) + f(coins,i,amount-coins[i]);
    }
    int change(int amount, vector<int>& coins) {
        return f(coins,0,amount);
    }
};
