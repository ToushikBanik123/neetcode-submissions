class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> count(numCourses);
        vector<vector<int>> adj(numCourses,vector<int>(0));
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            count[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(count[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int curent = q.front(); q.pop();
            for(auto x : adj[curent]){
                count[x]--;
                if(count[x] == 0){
                    q.push(x);
                }
            }
        }
        for(auto x : count){
            if(x != 0) return 0;
        }
        return 1;
    }
};