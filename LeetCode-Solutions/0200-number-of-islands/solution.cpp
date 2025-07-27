#define rep(i,n) for(int i = 0; i<n; ++i)

class Solution {
public:

    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,1,-1,0};

    void dfs(pair<int,int> src, vector<vector<char>>& g) {
        auto [ux,uy] = src; int  n = g.size(), m = g[0].size();
        g[ux][uy] = 0;
        for(int d = 0; d<4; ++d){
            int vx = ux + dx[d], vy = uy + dy[d];
            if(vx >= 0 && vx<n && vy >= 0 && vy<m && g[vx][vy] == '1'){dfs({vx,vy},g);}
        }
    }


    int numIslands(vector<vector<char>>& g) {
        int ans = 0, n = g.size(), m = g[0].size();
        rep(i,n) rep(j,m){
            if(g[i][j] == '1') {dfs({i,j},g); ++ans;}
        }
        return ans;
    }
};
