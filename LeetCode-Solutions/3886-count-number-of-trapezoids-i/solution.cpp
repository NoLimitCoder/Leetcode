const int MOD = 1e9 + 7;
typedef long long ll;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int> mp;
        for(auto p : points) mp[p[1]]++; vector<ll> c;
        for(auto it : mp){
            ll x = it.second;
            if(x > 1) c.push_back( (x*(x-1)/2)%MOD);
        }
        ll s = 0, ans = 0;
        for(int i = 0; i<c.size(); ++i){
            ans = (ans + c[i]*s) % MOD;
            s = (s+c[i])%MOD;
        }
        return ans;
    }
};
