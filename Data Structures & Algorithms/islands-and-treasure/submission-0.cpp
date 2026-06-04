class Solution {
public:
    void bfs(int i, int j, vector<vector<int>> & grid){
        queue<tuple<int,int,int>> q;
        q.push({i,j,0});
        int adj[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            auto[a,b,cary] = q.front();
            q.pop();
            for(auto x : adj){
                int r = a + x[0];
                int c = b + x[1];
                if(0 <= r && 0 <= c && r < grid.size() && c < grid[0].size() && grid[r][c] > cary+1){
                    grid[r][c] = cary +1;
                    q.push({r,c,cary+1});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0) bfs(i,j,grid);
            }
        }
    }
};
