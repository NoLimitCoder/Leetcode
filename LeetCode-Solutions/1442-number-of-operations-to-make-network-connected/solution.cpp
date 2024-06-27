#pragma GCC optimize("O3,unroll-loops")

class Solution {
public:

struct DSU{
    int n; vector<int> p, sz;
    DSU(int n): n(n),p(n),sz(n,1) {for(int i=0;i<n;++i)p[i]=i;}
    int size(){return n;}
    int get(int x){return p[x]==x? x : p[x]=get(p[x]);}
    bool unite(int x, int y){
        x = get(x); y = get(y); if(x==y) return 0;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y]; p[y] = x; --n; return 1;
    }
};

    int makeConnected(int n, vector<vector<int>>& A) {
        if(A.size()<n-1){return -1;} 
        DSU dsu(n); for(int i = 0; i<A.size(); ++i){ dsu.unite(A[i][0], A[i][1]); }
        return dsu.size()-1;
    }
};
