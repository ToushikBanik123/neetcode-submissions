class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n+1,0);
        vector<int> t(n+1,0);

        for(auto x : trust){
            t[x[0]]++;
            degree[x[1]]++;
        }
        for(int i = 0; i <= n; i++){
            if(degree[i] == n-1 && t[i] == 0) return i;
        }
        return -1;
    }
};