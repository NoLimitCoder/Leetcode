#pragma GCC optimize("O3,unroll-loops")
typedef vector<vector<int>> VVI;

class Solution {
public:

    void dfs(int u, int cur, VVI &adj, VVI &ans, vector<bool> &vis){
        vis[u] = 1;
        for(auto v : adj[u]){
            if(!vis[v]){
                ans[v].push_back(cur);
                dfs(v,cur,adj,ans,vis);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        VVI adj(n);
        for(int i = 0; i<edges.size(); ++i){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
        }
        VVI ans(n);
        for(int i = 0; i<n; ++i){
            vector<bool> vis(n,0);
            dfs(i,i,adj,ans,vis);
        }
        return ans;
    }
};
