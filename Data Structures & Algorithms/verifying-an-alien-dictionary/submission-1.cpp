class Solution {
   public:
    bool isLarge(string& w1, string& w2, map<char, int>& mp) {
        for (int j = 0; j < w1.size(); j++) {
            if (w2.size() == j) return true;
            if (mp[w1[j]] > mp[w2[j]]) return true;
            if (mp[w1[j]] < mp[w2[j]]) return false;
        }
        return false;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;
        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            // if W1 > W2 the order brakes
            if (isLarge(w1, w2, mp)) return false;
        }
        return true;
    }
};