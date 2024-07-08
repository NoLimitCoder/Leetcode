auto init = [](){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
#define rep(i,n) for(int i = 0; i<n; ++i)
typedef vector<int> VI; typedef vector<VI> VVI;
class Solution {
public:

bool flag;
VVI adj;
VI vis;
//cycle check | 0->unvisited | 1->processing | 2->visited

    void dfs(int u){
        vis[u] = 1;
        for(int v : adj[u]){
            if(!vis[v]) 
                dfs(v);
            else if(vis[v] == 1){flag = 0; return;}
        }
        vis[u] = 2;
    }

    bool canFinish(int N, vector<vector<int>>& A) {
        vis = VI(N,0); adj = VVI(N,VI(0)); flag = 1;
        rep(i,A.size()){
            int u = A[i][0], v = A[i][1];
            adj[v].push_back(u);
        }
        rep(u,N){
            if(!vis[u])
                dfs(u);
        }
        return flag;
    }
};
