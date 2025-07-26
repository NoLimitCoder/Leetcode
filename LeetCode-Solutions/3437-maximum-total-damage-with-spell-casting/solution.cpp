typedef long long ll;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& nums) {
        unordered_map<ll,ll> mp; vector<ll> A; for(ll i : nums){if(!mp[i]) A.push_back(i); mp[i]+= i;}
        sort(A.begin(), A.end()); int n = A.size();
        vector<ll> dp(n+5); 
        for(int i = 0; i<n; ++i){
            //constraints -> can not go to [ A[i]-1, A[i]-2 ]
            for(int k = 1; k<=2; ++k){
                if( (i-k >= 0) && A[i-k] != A[i]-1 && A[i-k] != A[i]-2){
                    dp[i] = max(dp[i], dp[i-k] + mp[A[i]]);
                }
            }
            //no constraint -> can update from cumulative max from [0...i-3] as it is guaranteed to be < A[i-2]
            if(i-3 >= 0) dp[i] = max(dp[i], dp[i-3] + mp[A[i]]);
            else         dp[i] = max(dp[i],     0   + mp[A[i]]); // can always reach from "empty set"
            //skip -> keeps cumulative max on range [0...i], dp is independent from A
            if (i-1 >= 0) dp[i] = max(dp[i], dp[i-1]);
        }
        return dp[n-1];
    }
};
