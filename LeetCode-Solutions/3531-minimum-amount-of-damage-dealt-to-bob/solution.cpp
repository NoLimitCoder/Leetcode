auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
#define rep(i,n) for(long long i = 0; i<n; ++i)
typedef long long ll;
typedef pair<ll,ll> pll;
class Solution {
public:
    ll minDamage(int p, vector<int>& A, vector<int>& B) {
        ll n = A.size(), sum = 0, ans = 0;
        rep(i,n) { B[i] = ceil((1.0*B[i])/(p*1.0)); sum += A[i]; }
        vector<pll> v(n);
        rep(i,n) { v[i] = {A[i],B[i]}; }
        sort(v.begin(), v.end(), [](const pll &a, const pll &b){
            return (1.0*a.second) / (1.0*a.first) < (1.0*b.second) / (1.0*b.first);
        });
        rep(i,n){
            ans += sum*v[i].second;
            sum -= v[i].first;
        }
        return ans;
    }
};
