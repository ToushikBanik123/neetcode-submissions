class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degreeArr(n+1,0);
        vector<int> trustArr(n+1,0);

        for(auto x : trust){
            trustArr[x[0]]++;
            degreeArr[x[1]]++;
        }
        for(int i = 0; i <= n; i++){
            if(degreeArr[i] == n-1 && trustArr[i] == 0) return i;
        }
        return -1;
    }
};