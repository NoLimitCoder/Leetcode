class Solution {
public:
    int deleteAndEarn(vector<int>& A) {
        vector<int> mp(10005,0);
        int mx = 0;
        for(int i : A) {mp[i] += i; mx = max(mx,i);}
        vector<int> dp(mx+5);
        dp[1] += mp[1];
        for(int i = 2; i<=mx; ++i){
            //dp[i+1] = max(dp[i+1], dp[i]);
            //dp[i+2] = max(dp[i+2], dp[i] + mp[i]);
            dp[i] = max(dp[i-1], dp[i-2] + mp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
