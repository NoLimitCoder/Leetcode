#define rep(i,n) for(int i = 0; i<n; ++i)
typedef vector<int> VI; typedef vector<VI> VVI;
const int INF = 2e9;
class Solution {
public:

int dx[4] = {1,-1,0, 0};
int dy[4] = {0, 0,1,-1};
struct P {int x, y;};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        //bfs
        VVI D(n, VI(m,INF));
        queue<P> q;
        rep(i,n) rep(j,m) {
            if(grid[i][j] == 2) {D[i][j] = 0; q.push({i,j});}
            if(grid[i][j] == 0) {D[i][j] = 0;}
        }
        while(!q.empty()){
            P u = q.front(); q.pop();
            for(int k = 0; k<4; ++k){
                P v = {u.x+dx[k],u.y+dy[k]};
                if(v.x < 0 || v.x >= n || v.y < 0 || v.y >= m ||
                   grid[v.x][v.y] == 0 || D[v.x][v.y] != INF) continue;
                D[v.x][v.y] = D[u.x][u.y]+1;
                q.push(v);
            }
        }
    int mx = 0;
    rep(i,n) rep(j,m) {
        mx = max(mx, D[i][j]);
    }
    return mx == INF? -1 : mx;
    }
};
