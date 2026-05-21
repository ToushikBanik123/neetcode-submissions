class Solution {
public:
    void expand(string& s, int i, int j, vector<vector<bool>>& mp, int n) {
        if (i >= 0 && j < n && s[i] == s[j]) {
            mp[i][j] = true;
            expand(s, i - 1, j + 1, mp, n);  // Bug 1 fixed: move pointers
        }
    }

    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> mp(n, vector<bool>(n, false));  

        for (int i = 0; i < n; i++) {      
            mp[i][i] = true;               
            expand(s, i - 1, i + 1, mp, n); 
            if (i + 1 < n && s[i] == s[i + 1]) {
                mp[i][i + 1] = true;
                expand(s, i - 1, i + 2, mp, n); 
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)          
            for (int j = i; j < n; j++)
                if (mp[i][j]) count++;

        return count;
    }
};