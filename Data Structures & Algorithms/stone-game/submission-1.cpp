class Solution {
public:
    map <pair<int,int> , int> mp;

    int dfs(vector<int>& piles, int i, int j){
        if(i > j) return 0;
        if(mp.find({i,j}) != mp.end()) return mp[{i,j}];

        bool even = ((j - i + 1) % 2 == 0);
        int left = even ? piles[i] : 0;
        int right = even ? piles[j] : 0;

        return mp[{i,j}] = max(left + dfs(piles,i+1,j) , right + dfs(piles,i,j-1));
    }
    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(),piles.end(),0);
        int alicesScore = dfs(piles, 0, piles.size()-1);
        return alicesScore > total - alicesScore;
    }
};