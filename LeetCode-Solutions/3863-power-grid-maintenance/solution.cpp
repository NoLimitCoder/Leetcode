class Solution {
public:

    struct DSU{
        int size; vector<int> p, sz; vector<pair<int,int>> st;
        DSU(int n): size(n), p(n), sz(n,1), st(n){for(int i = 0; i<n; ++i){p[i] = i; st[i] = {i,i};} }
        int get(int x){return p[x] == x? x: p[x] = get(p[x]);}
        bool sameSet(int x, int y){return get(x) == get(y);}
        bool unite(int x, int y){
            x = get(x); y = get(y); if(x==y) return 0;
            if(sz[x] < sz[y]) swap(x,y);
            st[x].first = min(st[x].first, st[y].first);
            st[x].first = max(st[x].second, st[y].second);
            sz[x] += sz[y]; p[y] = x; --size; return 1;
        }
    };
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
      DSU dsu(c+1);
        for(auto &e : connections) dsu.unite(e[0], e[1]);
        vector<int> rt(c+1); for(int i = 1; i<= c; ++i) rt[i] = dsu.get(i);
        unordered_map<int,set<int>>grid;
        vector<bool> on(c+1,1);
        for(int i = 1; i<=c; ++i) grid[rt[i]].insert(i);
        vector<int> ans;
        for(auto q: queries){
            int t = q[0], x = q[1], r = rt[x];
            if(t == 1){
                if(on[x])ans.push_back(x);
                else if(grid[r].empty()) ans.push_back(-1);
                else ans.push_back(*grid[r].begin());
            }
            else{
                if(on[x]){on[x] = 0; grid[r].erase(x);}
            }
        }
        return ans;
    }
};
