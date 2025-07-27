class Solution {
public:
    int maxProfit(vector<int>& P) {
        int n = P.size();
        vector<vector<int>> dp(n,vector<int>(2));

        //dp[i][0] -> max val at day i if sell
        //dp[i][1] -> max val at day i if buy
        /*
            transitions: dp[i][0] -> dp[i][1] - val
                         dp[i][1] -> dp[i][0] + val
                         dp[i][0] - > dp[i][0] //hold right to buy
                         dp[i][1] - > dp[i][1] //hold right to sell
        */
        dp[0][0] = 0; dp[0][1] = -P[0];
        for(int i = 1; i<n; ++i){
            dp[i][0] = max(dp[i-1][0],  dp[i-1][1] + P[i]);
            dp[i][1] = max(dp[i-1][1],  dp[i-0][0] - P[i]);
        }
        return  dp[n-1][0];
    }
};
