class Solution {
public:
    void f(int n, int i, string val, int score, vector<string> &ans){
        if(i==2*n){
            if(score == 0){
                ans.push_back(val);
            }
            return;
        }
        f(n,i+1,val+"(",score+1,ans);
        if(score>0)
        f(n,i+1,val+")",score-1,ans);
    }
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {};
        vector<string> ans;
        f(n,1,"(",1,ans);
        return ans;
    }
};
