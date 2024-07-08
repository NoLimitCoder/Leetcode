class Solution {
public:


const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
struct P {int x, y;};

    void dfs(P p, vector<vector<int>>& grid, int &ans) {
        if(p.x < 0 || p.x >= grid.size()|| p.y < 0 || p.y >= grid[0].size() || grid[p.x][p.y] == 0) return;
        grid[p.x][p.y] = 0;
        ++ans;
        for(int k = 0; k<4; ++k){
            dfs({p.x+dx[k],p.y+dy[k]},grid,ans);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, mx = 0;
        for(int i = 0; i<grid.size(); ++i){
            for(int j = 0; j<grid[0].size(); ++j){
                if(grid[i][j] != 0){ dfs({i,j},grid,ans); }
                mx = max(mx,ans); ans = 0;
            }
        }
    return mx;
    }
};
