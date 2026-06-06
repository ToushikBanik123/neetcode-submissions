class Solution{
    public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int srcColor = image[sr][sc];

        vector<vector<int>> ans = image;

        vector<vector<bool>> visited(n,vector<bool>(m,0));
        queue<pair<int,int>> q;
        visited[sr][sc] = 1;
        q.push({sr,sc});
        int adj[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            pair<int,int> curent = q.front(); q.pop();
            
            ans[curent.first][curent.second] = newColor;
            
            for(auto x : adj){
                int cr = curent.first + x[0];
                int cc = curent.second + x[1];
                if(0 <= cr && 0 <= cc && cr < n && cc < m && !visited[cr][cc] && image[cr][cc] == srcColor){
                    visited[cr][cc] = 1;
                    q.push({cr,cc});
                }
            }
        }
        return ans;
    }
};
