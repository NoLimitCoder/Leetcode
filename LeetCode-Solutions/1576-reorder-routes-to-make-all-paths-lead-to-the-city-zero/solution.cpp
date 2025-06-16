class Solution {
public:

vector<pair<int,int>> ans;
vector<vector<int>>AL;
vector<int> vis;
void dfs(int u, int p){
    vis[u] = 1; ans.push_back({u,p});
    for(int v : AL[u]){
        if(!vis[v]) dfs(v,u);
    }
}


    int minReorder(int n, vector<vector<int>>& E) {
        AL.assign(n,vector<int>(0));
        ans.assign({});
        vis.assign(n,0);
        set<pair<int,int>>st;
        for(auto it : E){
            int u = it[0], v = it[1];
            AL[u].push_back(v); AL[v].push_back(u);
            st.insert({u,v});
        }
        dfs(0,0);
        int res = 0;
        for(auto p : ans){
                if(st.find(p) == st.end()) ++res;
        }
        return res-1;
    }
};
