typedef long long ll;
typedef pair<ll,int> P;
const ll INF = 4e18;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& E, vector<bool>& on, long long k) {
        int n = on.size(), m = E.size();
        vector<vector<pair<int,ll>>>AL(n);
        vector<ll> res;
        for(auto e : E){
            int u = e[0], v = e[1], c = e[2];
            AL[u].emplace_back(v,c); res.push_back(c);
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        int lo = 0, hi = res.size()-1, ans = -1;
        vector<ll> d(n);
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            ll cur = res[mid];
            d.assign(n,INF);
            priority_queue<P,vector<P>,greater<P>>pq;
            d[0] = 0; pq.push({0,0});
            while(!pq.empty()){
                auto [dist, u] = pq.top(); pq.pop();
                if(dist > d[u]) continue;
                for(auto [v,c] : AL[u]){
                    if(c < cur || !on[v]) continue;
                    ll nd = dist + c;
                    if(nd < d[v]){d[v] = nd; pq.push({nd,v});}
                }
            }
            if(d[n-1] <= k){ans = cur; lo = mid+1;}
            else {hi = mid-1;}
        }
        return ans;
    }
};
