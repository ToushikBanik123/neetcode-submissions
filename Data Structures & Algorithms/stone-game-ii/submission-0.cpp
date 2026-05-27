class Solution {
public:
    map<tuple<int,int,bool>, int> memo;

    int dfs(vector<int>& arr, int i, int m, bool a) {
        if (i >= (int)arr.size()) return 0;
        auto key = make_tuple(i, m, a);
        if (memo.count(key)) return memo[key];

        int ans = a ? 0 : INT_MAX;
        int temp = 0;
        int j = i;

        while (j < i + 2*m && j < (int)arr.size()) {
            temp += arr[j];
            if (a)
                ans = max(ans, temp + dfs(arr, j+1, max(j-i+1, m), false));
            else
                ans = min(ans, dfs(arr, j+1, max(j-i+1, m), true));
            j++;
        }

        return memo[key] = (ans == INT_MAX ? 0 : ans);
    }

    int stoneGameII(vector<int>& piles) { return dfs(piles, 0, 1, 1); }
};