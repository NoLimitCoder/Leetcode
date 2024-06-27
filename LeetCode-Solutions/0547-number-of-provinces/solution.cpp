class Solution {

struct DSU{
    int n; vector<int> p, sz;
    DSU(int n): n(n), p(n), sz(n,1) {for(int i = 0; i<n; ++i)p[i] = i;}
    int size(){return n;}
    int get(int x){return p[x]==x? x : p[x] = get(p[x]);}
    bool unite(int x, int y){
        x = get(x); y = get(y); if(x==y)return 0;
        if(sz[x] < sz[y])swap(x,y);
        sz[x] += sz[y]; p[y] = x; --n; return 1;
    }
};

public:
    int findCircleNum(vector<vector<int>>& A) {
        int n = A.size();
        DSU dsu(n);
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                if(i==j)continue;
                if(A[i][j]){dsu.unite(i,j);}
            }
        }
        return dsu.size();
    }
};
