class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans; 
        int i = 0;
        while(true){
            char c = strs[0][i];
            for(int j = 0; j < strs.size(); j++){
                if(i >= strs[j].size() || strs[j][i] != c) return ans;
            }
            ans += c;
            i++;
        }
    }
};