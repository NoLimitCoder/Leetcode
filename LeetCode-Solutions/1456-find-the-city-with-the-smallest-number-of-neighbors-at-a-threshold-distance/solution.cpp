auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
#define rep(i,n) for (int i = 0; i < n; ++i)
typedef vector<int> VI; typedef vector<VI> VVI; 
const int INF = 1e9;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& E, int d) {
        //Distance matrix
        VVI D(n, VI(n, INF));
        //base cases
        rep(i,n) { D[i][i] = 0; }
        //getting input from EL to AM (D)
        rep(i,E.size()){ 
            int u = E[i][0], v = E[i][1], w = E[i][2]; 
            D[u][v] = w; D[v][u] = w; 
        }
        //floyd-warshall
        rep(k,n) rep(i,n) rep(j,n){ D[i][j] = min(D[i][j], D[i][k] + D[k][j]); }
        
        int ans = INF, idx = 0;
        rep(i,n){
            int tmp = 0;
            rep(j,n){
                if(D[i][j] <= d) ++tmp; 
            }
            if(tmp<=ans) {ans = tmp; idx = i;}
        }
        return idx;
    }
};
