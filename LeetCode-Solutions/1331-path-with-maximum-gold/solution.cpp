typedef vector<int> VI;
typedef vector<VI> VVI;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,-1,1};
class Solution {
public:

    struct pos{
        int x, y;
    };

    int mx = 0;
    void dfs(pos cur, int x, VVI& grid){
        int m = grid.size(), n = grid[0].size();
        if (cur.x < 0 || cur.x >= m ||cur.y < 0 || cur.y >= n || grid[cur.x][cur.y] == 0) return;
        int tmp = grid[cur.x][cur.y];
        x+=tmp;
        grid[cur.x][cur.y] = 0;
        mx = max(mx, x);
        for (int k = 0; k < 4; ++k) {
            pos nxt = {cur.x + dx[k], cur.y + dy[k]};
            dfs(nxt, x, grid);
        }
        //x -= tmp;
        grid[cur.x][cur.y] = tmp;
    }



    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dfs({i,j},0,grid);
                //cout << '\n';
            }
        }
        return mx;
    }
};
