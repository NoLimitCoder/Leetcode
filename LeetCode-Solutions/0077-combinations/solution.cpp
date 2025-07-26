class Solution {
public:

    vector<vector<int>> ans;
    int N, K;
    void dfs(int d, int deph, vector<int> tmp){
        if(tmp.size() == K) {ans.push_back(tmp); return;}
        for(int v = d+1; v<=N; ++v){
            tmp.push_back(v);
            dfs(v,deph+1,tmp);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        ans.clear(); N = n; K = k;
        vector<int> tmp;
        dfs(0,0,tmp);
        return ans;
    }
};
