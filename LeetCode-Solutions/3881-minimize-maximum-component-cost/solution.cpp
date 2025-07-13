class Solution {
public:

        struct DSU{
            vector<int> p, r;
            DSU(int n): p(n), r(n) {iota(p.begin(), p.end(), 0);}
            int f(int x) {return p[x] == x? x : p[x]=f(p[x]);}
            bool unite(int a, int b){
                a = f(a); b = f(b); if(a==b) return 0;
                if(r[a]<r[b]) swap(a,b);
            p[b] = a; if(r[a]==r[b]) r[a]++; return 1;
            }
        };
    
    int minCost(int n, vector<vector<int>>& e, int k) {
        sort(e.begin(), e.end(), [](auto &a, auto &b){
           return a[2] < b[2]; 
        });
        DSU dsu(n); vector<int> ans;
        for(auto u : e){
            if(dsu.unite(u[0], u[1])){
                ans.push_back(u[2]);
                if(ans.size() == n-1) break;
            }
        }
        if(k >=n) return 0;
        sort(ans.begin(), ans.end());
        return ans[n-k-1];
    }
};
