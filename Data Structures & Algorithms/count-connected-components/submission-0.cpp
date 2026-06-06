class Solution {
   public:
    void dfs(int i, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[i] = 1;
        for (auto x : adj[i]) {
            if (!visited[x]) {
                dfs(x, visited, adj);
            }
        }
    }
    int countComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<bool> visited(V, 0);
        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj);
                count++;
            }
        }
        return count;
    }
};
