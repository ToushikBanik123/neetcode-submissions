class Solution {
public:
    void f(vector<int>& c, int t, int i, vector<int>& a, int sum, vector<vector<int>>& ans) {
        if (sum == t) { ans.push_back(a); return; }
        if (i >= (int)c.size() || sum > t) return;

        for (int j = i; j < (int)c.size(); j++) {
            if (j > i && c[j] == c[j-1]) continue;
            a.push_back(c[j]);
            f(c, t, j+1, a, sum + c[j], ans);
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> a;
        f(candidates, target, 0, a, 0, ans);
        return ans;
    }
};