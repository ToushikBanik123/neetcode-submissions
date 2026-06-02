class Solution {
public:
    set<pair<int,int>> mp;

    int f(int i, int j, vector<vector<int>>& grid){
        if(mp.find({i,j}) != mp.end()) return 0;
        mp.insert({i,j});

        int ans = 0;
        set<pair<int,int>> directions;

        directions.insert({i-1,j});
        directions.insert({i+1,j});
        directions.insert({i,j-1});
        directions.insert({i,j+1});

        for(auto x : directions){
            if(x.first < 0 || grid.size() <= x.first || x.second < 0 || grid[i].size() <= x.second){
                ans++;
            }else if(grid[x.first][x.second] == 0){
                ans++;
            }else{
                ans += f(x.first,x.second,grid);
            }
        }
        return ans;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    return f(i,j,grid);
                }
            }
        }
        return 0;
    }
};