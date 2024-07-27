auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
#define rep(i,n) for(int i = 0; i<n; ++i)
typedef long long ll;
typedef vector<ll> VI; typedef vector<VI> VVI;
const ll INF = 1e10;
class Solution {
public:
    ll minimumCost(string s, string t, vector<char>& A, vector<char>& B, vector<int>& C) {
        int n = 26;
        VVI D(n, VI(n, INF)); rep(i,n) D[i][i] = 0;
        rep(i,A.size()){
            ll u = A[i]-'a', v = B[i]-'a', w = C[i];
            D[u][v] = min(D[u][v], w);
        }
        //floyd-warshall
        rep(k,n) rep(i,n) rep(j,n) {D[i][j] = min(D[i][j], D[i][k] + D[k][j]);}
        ll ans = 0;
        rep(i,s.size()){
            ll u = s[i]-'a', v = t[i]-'a';
            if(D[u][v] == INF) return -1;
            ans += D[u][v];
        }
        return ans;
    }
};
