auto init = []() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
struct DSU{
  int n; vector<int> p, sz, cost;
  DSU(int n): n(n), p(n), cost(n,-1), sz(n,1){for(int i=0;i<n;++i) p[i]=i;}
  int size(){return n;}
  int get(int x){return p[x]==x? x : p[x] = get(p[x]);}
  int getCost(int x){return cost[get(x)];}
  bool sameSet(int x, int y){return get(x)==get(y);}
  bool unite(int x, int y, int w){
    x = get(x); y = get(y); if(x==y) {cost[x] &= w; return 0;}
    if(sz[x] < sz[y]) swap(x,y);
    sz[x] += sz[y]; p[y] = x; --n; 
    cost[x] &= w; cost[x] &= cost[y];
    return 1;
  }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        DSU dsu(n);
        for(int i = 0; i<E.size(); ++i){
            int u = E[i][0], v = E[i][1], w = E[i][2];
            dsu.unite(u,v,w);
        }
        vector<int> ans;
        for(int i = 0; i<Q.size(); ++i){
            int u = Q[i][0], v = Q[i][1];
            if(dsu.sameSet(u,v)) ans.push_back(dsu.getCost(u));
            else ans.push_back(-1);
        }
        return ans;
        
    }
};
