class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> mp(n,vector<bool>(n,false));
        int count = 0;
        for(int i = n-1; 0 <= i; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j-i <= 2 || mp[i+1][j-1])){
                    mp[i][j] = 1;
                    count++;
                }
            }
        }
        return count;
    }
};
