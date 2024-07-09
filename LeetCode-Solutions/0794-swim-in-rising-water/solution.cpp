auto init = [](){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
typedef vector<int> vi;
int dx[4] = {1,-1,0, 0};
int dy[4] = {0, 0,1,-1};

struct Cell {
        int t, x, y;
        bool operator < (const Cell &d) const {return t > d.t;}
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& G) {
        //BFS since there's no cycle
        int ans = 0, n = G.size();
        priority_queue<Cell>  pq; pq.push({G[0][0], 0, 0});
        vector<vi> V(n, vi(n,0)); V[0][0] = 1;
        while(!pq.empty()){
            auto [t,x,y] = pq.top(); pq.pop();
            ans = max(ans, t);
            if(x==n-1 && y == n-1) return ans;
            for(int k = 0; k<4; ++k){
                if(x+dx[k] < 0 || x+dx[k] >= n || y+dy[k] < 0 || y+dy[k] >= n || V[x+dx[k]][y+dy[k]] != 0) continue;
                V[x+dx[k]][y+dy[k]] = 1;
                pq.push({G[x+dx[k]][y+dy[k]], x+dx[k], y+dy[k]});
            }
        }
        return ans;
    }
};
