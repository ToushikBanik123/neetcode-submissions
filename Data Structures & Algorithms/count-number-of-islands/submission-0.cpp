class Solution {
public:
    void visit(int i, int j, set<pair<int,int>> &visited,vector<vector<char>>& grid){
        visited.insert({i,j});
        vector<vector<int>> shift = {{0,+1},{0,-1},{+1,0},{-1,0}};

        for(auto x : shift){
            int s = i+x[0];
            int e = j+x[1];
            if(0 <= s && s < grid.size() && 0 <= e && e < grid[s].size() && visited.find({s,e}) == visited.end() && grid[s][e] == '1'){
                visit(s,e,visited,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        set<pair<int,int>> visited;
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1' && visited.find({i,j}) == visited.end()){
                    count++;
                    visit(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};
