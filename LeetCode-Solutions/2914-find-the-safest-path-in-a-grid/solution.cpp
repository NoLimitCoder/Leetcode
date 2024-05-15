#pragma GCC optimize("O3","unroll-loops")

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<vector<bool>> VVB;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
class Solution {
public:

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
const int INF = 2e9;

struct pos{int x, y;};

    //multisource bfs to compute distances
    void bfs(VVI &MinD, vector<pos> &srcs, VVI &grid){
        int n = grid.size(); 
        queue<pos> q;
        for(pos src : srcs)
            {q.push(src); MinD[src.x][src.y] = 0;}
        while(!q.empty()){
            pos v = q.front(); q.pop();
            for(int k = 0; k<4; ++k){
                if(v.x+dx[k] < 0 || v.x+dx[k] >= n || v.y+dy[k] < 0 || v.y+dy[k] >= n || MinD[v.x+dx[k]][v.y+dy[k]] != INF)
                    continue;
                MinD[v.x+dx[k]][v.y+dy[k]] = 1 + MinD[v.x][v.y];
                q.push({v.x+dx[k],v.y+dy[k]});
            }
        }
    }

    //bfs to explore graph to see if it connects
    bool bfs2(VVB& V, pos src, VVI &grid){
        int n = grid.size(); 
        queue<pos> q;
        if(V[0][0] || V[n-1][n-1]) return 0;
        q.push(src); V[src.x][src.y] = 1;
        while(!q.empty()){
            pos v = q.front(); q.pop();
            if (v.x == n-1 && v.y == n-1) return true;
            for(int k = 0; k<4; ++k){
                if(v.x+dx[k] < 0 || v.x+dx[k] >= n || v.y+dy[k] < 0 || v.y+dy[k] >= n || V[v.x+dx[k]][v.y+dy[k]] == 1)
                    continue;
                V[v.x+dx[k]][v.y+dy[k]] = 1;
                q.push({v.x+dx[k],v.y+dy[k]});
            }
        }
        return V[n-1][n-1];
    }


    //binary search the answer
    int BS(VVI& MinD, VVB &V){
        int n = MinD.size(), hi = n + 1, lo = 0, mid, res = -1;
        while(lo<=hi){
            V = VVB(n, vector<bool>(n,0));
            mid = (hi+lo)/2;
            rep(i,n) rep(j,n) if(MinD[i][j] < mid) V[i][j] = 1;
            if(bfs2(V, {0,0}, MinD))
                {lo = mid+1; res = mid;}
            else 
                {hi = mid-1;}
        }
        return res;
    }


    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios();
        int n = grid.size();
        VVI MinD(n, VI(n,INF)); VVB V; vector<pos> thiefs;
        rep(i,n) rep(j,n) if(grid[i][j] == 1) thiefs.push_back({i,j});
        bfs(MinD, thiefs, grid);
        return BS(MinD, V);
    }
};
