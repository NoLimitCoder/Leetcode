auto init = [](){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef tuple<int, int, int> iii;
typedef vector<iii> viii;
#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:

struct DSU{
    int n; vi p, sz;
    DSU(int n): n(n), p(n), sz(n,1) {rep(i,n) p[i] = i;}
    int size(){return n;}
    int get(int x){return p[x]==x? x : p[x] = get(p[x]);}
    bool unite(int x, int y){
        x=get(x); y=get(y); if(x==y) return 0;
        if(sz[x] < sz[y]) swap(x,y);
        sz[x] += sz[y]; p[y] = x; --n; return 1;
    }
};


    int minCostConnectPoints(vector<vector<int>>& P) {
        int n = P.size();
        viii EL;
        rep(i,n)
            for(int j = i+1; j<n; ++j){
               //point idx will be their position in the grid (i) (j)
                int w = abs(P[i][0] - P[j][0]) + abs(P[i][1] - P[j][1]);
                EL.push_back({w, i, j});
            }
        sort(EL.begin(), EL.end());
        DSU dsu(n);
        int ans = 0;
        for(auto & [w,u,v] : EL){
            if(dsu.unite(u,v)) ans += w;
            if(dsu.size() == 1) break;
        }
        return ans;
    }

};
