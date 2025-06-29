#define rep(i,n) for(int i = 0; i<n; ++i)
#define rep1(i,n) for(int i = 1; i<=n; ++i)
typedef long long ll;
const ll INF = 1e18;
class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        ll n = nums.size(); vector<vector<ll>> dp(n+5, vector<ll>(k+5, INF)); vector<ll> tmp(n+5);
        for(int i = 0; i<n; ++i) tmp[i+1] = tmp[i] ^ nums[i];
        dp[0][0] = 0;
        rep1(i,n) rep1(j,min(k,i)) rep(l,i){
            if(dp[l][j-1] != INF)
                dp[i][j] = min(dp[i][j], max(dp[l][j-1], tmp[i]^tmp[l]));
        }
        return dp[n][k];
    }
};
