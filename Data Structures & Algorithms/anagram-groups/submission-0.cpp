class Solution {
public:
    string f(string s){
        sort(s.begin(),s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            string val = f(strs[i]);

            if(mp.find(val) != mp.end()){
                mp[val].push_back(strs[i]);
            }else{
                mp[val] = {strs[i]};
            }
        }
        vector<vector<string>> ans;
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
