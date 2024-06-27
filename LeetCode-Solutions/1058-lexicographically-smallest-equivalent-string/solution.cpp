#pragma GCC optimize("O3,unroll-loops")

class Solution {

struct DSU{
    int n; vector<int> p, sz, mn;
    DSU(int n): n(n), p(n), sz(n,1), mn(n) {for(int i = 0; i<n; ++i){p[i]=mn[i]=i;} }
    int get(int x){return p[x]==x? x : p[x]=get(p[x]);}
    char getMin(int x){return 'a'+mn[get(x)];}
    bool unite(int x, int y){
        x = get(x); y = get(y); if(x==y) return 0;
        if(sz[x]<sz[y])swap(x,y);
        sz[x] += sz[y]; p[y] = x; mn[x] = min(mn[x],mn[y]); --n; return 1;
    }
};

public:
    string smallestEquivalentString(string s1, string s2, string s3) {
        DSU dsu(26); string ans = "";
        for(int i = 0; i<s1.size(); ++i){ dsu.unite(s1[i]-'a', s2[i]-'a'); }
        for(int i = 0; i<s3.size(); ++i){ ans += dsu.getMin(s3[i]-'a'); }
        return ans;
    }
};
