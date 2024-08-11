#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '
class Solution {
public:
    int ans;
    int dfs(int u, vector<bool> &vis, vector<vector<int>> &AL, vector<int>&sz){
        vis[u] = 1; sz[u] = 1; int lc = 0; bool flag = 1;
        for(auto v : AL[u]){
            if(!vis[v]){
               // vis[v] = 1;
                int tmp = dfs(v,vis,AL,sz);
                sz[u] += tmp;
                if(lc == 0) lc = tmp;
                else if(lc != tmp) flag = 0;
            }
        }
        if(flag) ans++;
        return sz[u];
    }






    int countGoodNodes(vector<vector<int>>& E) {
        int n = E.size()+1;
        vector<vector<int>> AL(n);
        ans = 0;
        for(auto it : E){ int u = it[0], v = it[1]; AL[u].push_back(v); AL[v].push_back(u);}
        vector<int>sz(n,0); vector<bool> vis(n,0);
        dfs(0,vis,AL,sz);
        return ans;
    }
};
