typedef long long ll;
const ll INF = 4e18;
#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:
    ll maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>>dp(n,vector<ll>(3,-INF));
        ll ans = -INF;
        rep(i,n){
            if(i && nums[i] > nums[i-1]){ 
                dp[i][0] = max(dp[i-1][0] + nums[i], 1LL*nums[i] + 1LL*nums[i-1]);
                dp[i][2] = max(dp[i-1][2] + nums[i], 1LL*nums[i] + dp[i-1][1]);
            }
            if(i && nums[i] < nums[i-1]) 
                dp[i][1] = max(dp[i-1][1] + nums[i], 1LL*nums[i] + dp[i-1][0]);
            ans = max(ans,dp[i][2]);
        }
        return ans;
    }
};
