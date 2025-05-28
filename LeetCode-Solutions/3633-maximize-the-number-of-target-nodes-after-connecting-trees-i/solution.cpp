auto init = []() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
class Solution {
public:

    int BFS(int &src, int k, vector<vector<int>>&AL){
        int ans = 0;
        queue<int>q; vector<int>D(AL.size()+1,-1);
        q.push(src); D[src] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(D[u] == k+1) break;
            ans++;
            for(int v : AL[u]){
                if(D[v] == -1) {D[v] = D[u]+1; q.push(v); }
            }
        }
        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& E1, vector<vector<int>>& E2, int k) {
        int n = E1.size()+1, m = E2.size()+1, mx = 0; vector<int> ans;
        if(k == 0) return vector<int>(n,1);
        vector<vector<int>>AL1(n+1, vector<int>()), AL2(m+1, vector<int>());
        for(auto it : E1)
            { int u = it[0], v = it[1]; AL1[u].push_back(v); AL1[v].push_back(u); }
        for(auto it : E2)
            { int u = it[0], v = it[1]; AL2[u].push_back(v); AL2[v].push_back(u); }
        for(int j = 0; j<m; ++j)
            { mx = max(mx,BFS(j,max(0,k-1),AL2)); }
        for(int i = 0; i<n; ++i)
            { ans.push_back(BFS(i,k,AL1) + mx); }
        return ans;
    }
};
