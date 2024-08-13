auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:

    void dfs(int i, vector<int> tmp, int x, vector<int>& C, vector<vector<int>> &ans, int &n) {
        if(x == 0) {ans.push_back(tmp); return;}
        if(x<0 || i == n) return;
        //option1 take
        tmp.push_back(C[i]);
        dfs(i+1,tmp,x-C[i],C,ans,n);
        tmp.pop_back();
        //option 2 not take
        while(i < n-1 && C[i] == C[i+1]) ++i;
        dfs(i+1,tmp,x,C,ans,n);
    }

    vector<vector<int>> combinationSum2(vector<int>& C, int x) {
        sort(C.begin(), C.end());
        vector<vector<int>> ans;
        int n = C.size();
        dfs(0,{},x,C,ans,n);
        return ans;
    }   

};
