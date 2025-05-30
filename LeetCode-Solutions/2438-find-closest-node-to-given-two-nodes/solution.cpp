auto init = []() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
const int INF = 1e5+1;
class Solution {
public:
    void dfs(int src, int level, vector<int>&D, vector<int>&AL, vector<int> &vis){
        if(vis[src]) return;
        vis[src] = 1; D[src] = level;
        if(AL[src] != -1) 
            dfs(AL[src],level+1,D,AL,vis);
        
    }
    int closestMeetingNode(vector<int>& AL, int n1, int n2) {
        int n = AL.size(), ans = INF, idx = -1;
        vector<int> D1(n,-1), D2(n,-1), vis(n,0);
        dfs(n1,0,D1,AL,vis); vis.assign(n,0); dfs(n2,0,D2,AL,vis);
        for(int i = 0; i<n; ++i)
            if(D1[i] != -1 && D2[i] != -1)
                { if(max(D1[i],D2[i]) < ans) {ans = max(D1[i],D2[i]); idx = i;} }
        return idx;
    }
};
