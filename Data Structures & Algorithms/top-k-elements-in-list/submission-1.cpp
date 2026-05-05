class Solution {
    class Cmp{
        public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> q;
        for(auto x: mp){
            q.push(x);
        }
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
