class Solution {
public:
    int n; vector<int> P;
    int fd(int x) {return P[x] == x? x : P[x] = fd(P[x]);}
    
    bool can(int x, vector<vector<int>> &E, int k){
        P.resize(n); iota(P.begin(), P.end(), 0);
        int count = 0, vis = 0;
        for(auto &e : E){
            int u = e[0], v = e[1], w = e[2], m = e[3];
            if(m == 1){
                if(w < x) return 0;
                int pu = fd(u), pv = fd(v);
                if(pu == pv) return 0;
                P[pu] = pv; ++count;
            }
        }
        vector<array<int,3>>tx;
        for(auto &e : E){
            int u = e[0], v = e[1], w = e[2], m = e[3];
            if(m == 0)
                { int tp = (w >= x? 0 : (w*2 >= x? 1 : 2)); if(tp < 2) tx.push_back({tp,u,v}); }
        }
        sort(tx.begin(), tx.end());
        for(auto [t,u,v] : tx){
            int pu = fd(u), pv = fd(v); if(pu == pv) continue;
            if(t == 1 && vis == k) continue;
            if(t == 1) ++vis;
            P[pu] = pv; ++count;
        }
        return count == n-1;
    }
    int maxStability(int N, vector<vector<int>>& E, int k) {
        n = N;
        int lo = 1, hi = 1e6, ans = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(can(mid,E,k)){ ans = mid; lo = mid+1; }
            else {hi = mid-1;}
        }
        return ans;
    }
};
