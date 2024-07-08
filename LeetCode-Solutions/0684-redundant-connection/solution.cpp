class Solution {
public:

struct DSU{
    int n; vector<int> p, sz;
    DSU(int n): n(n), p(n), sz(n,1) {for(int i = 0; i<n; ++i) p[i] = i;}
    int size(){return n;}
    int get(int x){return p[x]==x? x : p[x] = get(p[x]);}
    bool unite(int x, int y){
        x = get(x); y = get(y); if(x==y) return 0;
        if(sz[x] < sz[y])swap(x,y);
        sz[x] += sz[y]; p[y] = x; --n; return 1;
    }
};

    vector<int> findRedundantConnection(vector<vector<int>>& E) {
        DSU dsu(E.size()+1);
        for(int i = 0; i<E.size(); ++i){
            int u = E[i][0], v = E[i][1];
            if(!dsu.unite(u,v)) return {u,v};
        }
        return {};
    }
};
