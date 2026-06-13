class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int N = words.size();

        vector<bool> present(26, false);
        for (auto& w : words)
            for (char c : w)
                present[c - 'a'] = true;

        int K = 0;
        for (int i = 0; i < 26; i++) if (present[i]) K++;

        set<pair<int,int>> adjs;

        for (int i = 0; i < N - 1; i++) {
            int len = min(words[i].size(), words[i+1].size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (words[i][j] != words[i+1][j]) {
                    adjs.insert({words[i][j] - 'a', words[i+1][j] - 'a'});
                    found = true;
                    break;
                }
            }

            if (!found && words[i].size() > words[i+1].size())
                return "";
        }

        vector<vector<int>> adj(26);
        vector<int> count(26, 0);

        for (auto& [u, v] : adjs) {
            adj[u].push_back(v);
            count[v]++;
        }

        queue<int> q;
        for (int i = 0; i < 26; i++)
            if (present[i] && count[i] == 0)
                q.push(i);

        string ans;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            ans += char('a' + cur);

            for (int x : adj[cur]) {
                count[x]--;
                if (count[x] == 0)
                    q.push(x);
            }
        }

        if ((int)ans.size() != K) return "";

        return ans;
    }
};