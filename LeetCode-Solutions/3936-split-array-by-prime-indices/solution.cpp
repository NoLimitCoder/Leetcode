typedef long long ll;
class Solution {
public:
    long long splitArray(vector<int>& a) {
        ll n = a.size();
        vector<bool> p(n,1);
        ll x = 0, y = 0;
        if(n>0)p[0] = 0; if(n>1) p[1] = 0;
        for(ll i = 2; i*i<n; ++i){
            if(p[i]){
                for(ll j = i*i; j<n; j+=i) p[j] = 0;
            }
        }
        for(ll i = 0; i<n; ++i) (p[i]? x : y) += a[i];
        return abs(x-y);
    }
};
