class Solution {
   public:
    void solve(int i, int n, int k, vector<int>& curr, vector<vector<int>>& res) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        if (i > n) return;

        // Include i
        curr.push_back(i);
        solve(i + 1, n, k, curr, res);
        curr.pop_back();

        // Exclude i
        solve(i + 1, n, k, curr, res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(1,n,k,curr,res);
        return res;
    }
};