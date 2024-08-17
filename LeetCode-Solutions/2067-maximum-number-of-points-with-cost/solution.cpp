auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
#define rep(i,n) for(int i =   0; i<n ; ++i)
#define per(i,n) for(int i = n-1; i>=0; --i)
typedef long long ll;
class Solution {
public:

    ll maxPoints(vector<vector<int>>& A){
        ll n = A.size(), m = A[0].size();
        vector<vector<ll>>dp(n+1, vector<ll>(m+1));
        rep(i,n) rep(j,m) dp[i][j] = A[i][j];        
        rep(i,n){
            //Prefix sum
            vector<ll> P(m, 0);
            rep(j,m){ P[j] = (j==0   ? max(P[j], dp[i][j]) : max({P[j], dp[i][j], P[j-1]-1})); }
            per(j,m){ P[j] = (j==m-1 ? max(P[j], dp[i][j]) : max({P[j], dp[i][j], P[j+1]-1})); }
            //push DP
            rep(j,m){dp[i+1][j] += P[j];}
        }
        ll ans = 0; rep(j,m) ans = max(ans, dp[n-1][j]); return ans;
    }
};
