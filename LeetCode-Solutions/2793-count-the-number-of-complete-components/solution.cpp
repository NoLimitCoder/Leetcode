struct DSU{
  int n; vector<int> p, sz,e;
  DSU(int n): n(n), p(n), e(n,0), sz(n,1){for(int i=0;i<n;++i) p[i]=i;}
  int size(){return n;}
  int get(int x){return p[x]==x? x : p[x] = get(p[x]);}
  bool sameSet(int x, int y){return get(x)==get(y);}
  bool unite(int x, int y){
    x = get(x); y = get(y); if(x==y) {e[x]++; return 0;}
    if(sz[x] < sz[y]) swap(x,y);
    e[x] += e[y]; e[x]++;
    sz[x] += sz[y]; p[y] = x; --n; return 1;
  }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& E) {
        DSU dsu(n);
        for(int i = 0; i<E.size(); ++i){
            dsu.unite(E[i][0],E[i][1]);
        }
        int ans = 0;
        for(int i = 0; i<n; ++i){
            if(i == dsu.get(i)){
                if(dsu.sz[i] == 1) ans++;
                else if(dsu.e[i] == (dsu.sz[i] *(dsu.sz[i]-1))/2) ans++;
            }
        }
        return ans;
    }
};
