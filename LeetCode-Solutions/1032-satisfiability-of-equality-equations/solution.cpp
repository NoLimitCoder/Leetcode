#pragma GCC optimize("O3,unroll-loops")

class Solution {
struct DSU{
    int n; vector<int> p, sz;
    DSU(int n): n(n), p(n), sz(n,1) {for(int i = 0; i<n; ++i)p[i]=i;}
    int size(){return n;}
    int get(int x){return p[x]==x? x : p[x]=get(p[x]);}
    bool sameSet(int x, int y){return get(x)==get(y);}
    bool unite(int x, int y){
        x = get(x); y = get(y); if(x==y)return 0;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y]; p[y] = x; --n; return 1;
    }
};

public:
    bool equationsPossible(vector<string>& A) {
        DSU dsu(26);
        for(int i = 0; i < A.size(); ++i)
            { if(A[i][1]== '=') dsu.unite(A[i][0]-'a',A[i][3]-'a'); }
        for(int i = 0; i < A.size(); ++i)
            { if(A[i][1]== '!' && dsu.sameSet(A[i][0]-'a',A[i][3]-'a')) return 0; }
         return 1;
    }
};
