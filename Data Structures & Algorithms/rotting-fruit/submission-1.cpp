class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        pair<int,int> tail;
        pair<int,int> nexttail;
        queue<pair<int,int>> q;
        int count = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    tail = {i,j};
                    q.push(tail);
                }
            }
        }

        int adj[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            pair<int,int> curent = q.front(); q.pop();
            for(auto x : adj){
                int r = curent.first + x[0];
                int c = curent.second + x[1];
                if(0 <= r && 0 <= c && r < n && c < m && grid[r][c] == 1){
                    nexttail = {r,c};
                    grid[r][c] = 2;
                    q.push(nexttail);
                }
            }
            if(curent == tail){
                tail = nexttail;
                count++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return max(count, 0);
    }
};
