auto init = [](){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define rep(i,n) for(int i = 0; i<n; ++i)
const int INF = 2e9;
vector<vii> AL;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& E, int n, int k) {
        AL = vector<vii>(n);
        //getting input
        rep(i,E.size()){
            int u = E[i][0], v = E[i][1], w = E[i][2]; u--; v--;
            AL[u].push_back({w,v});
        }
        int src = k-1;
        //dijkstra
        priority_queue<ii,vii,greater<ii>>pq; pq.push({0,src});
        vi D(n,INF); D[src]=0;
        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d > D[u]) continue;
            for(auto &[w,v] : AL[u]){
                if(D[u]+w < D[v]){
                    D[v] = D[u]+w;
                    pq.push({D[v], v});
                }
            }
        }
        int ans = 0;
        rep(i,n) ans = max(ans,D[i]);
        return ans == INF? -1 : ans;
    }
};
