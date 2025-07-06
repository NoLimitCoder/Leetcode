class Solution {
public:
   struct DSU{
        int size; vector<int> p, sz;
        DSU(int n): size(n), p(n), sz(n,1) {for(int i = 0; i<n; ++i){p[i] = i;}}
        int get(int x){return p[x] == x? x: p[x] = get(p[x]);}
        bool sameSet(int x, int y){return get(x) == get(y);}
        bool unite(int x, int y){
            x = get(x); y = get(y); if(x==y) return 0;
            if(sz[x] < sz[y]) swap(x,y);
            sz[x] += sz[y]; p[y] = x; --size; return 1;
        }
    };
    
    int minTime(int n, vector<vector<int>>& E, int k) {
        sort(E.begin(), E.end(), [](auto & a, auto &b){
           return a[2] < b[2]; 
        });
        vector<int> time; time.push_back(0);
        for(auto e : E) time.push_back(e[2]);
        sort(time.begin(), time.end());
        time.erase(unique(time.begin(), time.end()), time.end());
        int lo = 0, hi = time.size()-1, ans = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2, t = time[mid];
            DSU dsu(n);
            for(auto e : E){
                if(e[2] > t){dsu.unite(e[0],e[1]);}
            }
            if(dsu.size >= k){ans = t; hi = mid-1;}
            else{lo = mid+1;}
        }
        return ans;

    }
};
