auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
typedef vector<int> VI; typedef vector<VI> VVI;
typedef pair<int,int> ii;
const int INF = 2e9;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int c) {
        VVI AL(n+1);
        for(auto E : edges){ 
            int u = E[0], v = E[1];
            AL[u].push_back(v); AL[v].push_back(u);
        }
        queue<ii> q; VI _1st(n+1, INF), _2nd(n+1, INF);
        q.push({0, 1}); _1st[1] = 0;
        while (!q.empty()) {
            auto [w, u] = q.front(); q.pop();
            int t = w;
            if ((w / c) & 1) { t += c - (w % c); }
            t += time;
            for (int v : AL[u]) {
                if (t < _1st[v]) 
                    { _2nd[v] = _1st[v]; _1st[v] = t; q.push({t, v}); } 
                else if (t > _1st[v] && t < _2nd[v]) 
                    { _2nd[v] = t; q.push({t, v}); }
            }
        }
        return _2nd[n] == INF ? -1 : _2nd[n];
    }
};
