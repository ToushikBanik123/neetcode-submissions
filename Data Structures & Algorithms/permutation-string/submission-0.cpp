class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> mp(26, 0);
        vector<int> runingMp(26, 0);
        for(int i = 0; i < s1.size(); i++){
            mp[s1[i]-'a']++;
            runingMp[s2[i]-'a']++;
        }
        if(mp == runingMp) return 1;
        for(int i = s1.size(); i < s2.size(); i++){
            runingMp[s2[i - s1.size()]-'a']--;
            runingMp[s2[i]-'a']++;
            if(mp == runingMp) return 1;
        }
        return 0;
    }
};
