class Solution {
   public:
   map<pair<int,bool>,int> mp;

    int f(vector<int>& prices, int i, bool buying) {
        if (i >= prices.size()) return 0;
        if(mp.find({i,buying}) != mp.end()) return mp[{i,buying}];

        if (buying) {
            int c = f(prices, i + 1, buying);
            int b = f(prices, i + 1, !buying) - prices[i];
            return mp[{i,buying}] = max(c, b);
        } else {
            int c = f(prices, i + 1, buying);
            int s = prices[i] + f(prices, i + 2, !buying);
            return mp[{i,buying}] = max(c, s);
        }
    }
    int maxProfit(vector<int>& prices) {
        return f(prices,0,1);
    }
};
