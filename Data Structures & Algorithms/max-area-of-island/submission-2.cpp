class Solution {
public:
    int bfs(
     int i,
     int j,
     vector<vector<int>> &grid,
     vector<vector<int>> &visited){
        visited[i][j] = 1;
        int adj[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int count = 0;
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            pair<int,int> curent = q.front();
            q.pop();
            count++;
            
            for(auto x : adj){
                int r = curent.first + x[0];
                int c = curent.second + x[1];
                if(0<=r
                && 0 <= c
                && r < grid.size()
                && c < grid[0].size()
                && grid[r][c] == 1
                && visited[r][c] == 0
                ){
                    q.push({r,c});
                    visited[r][c] = 1;
                }
            }
        }
        return count;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 0 || m == 0) return 0;
        int ans = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0)
                    ans = max(bfs(i,j,grid,visited),ans);
            }
        }
        return ans;
    }
};