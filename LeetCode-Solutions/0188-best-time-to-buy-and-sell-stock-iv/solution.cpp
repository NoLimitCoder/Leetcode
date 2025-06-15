class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, INT_MIN)));
        dp[0][0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int f = 0; f <= 1; ++f) {
                    if (dp[i][j][f] == INT_MIN) continue; // unreachable
                    if (j < k && !f) {
                        // Buy -> become holding, stay in same j
                        dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][0] - prices[i]);
                        //skip
                        dp[i+1][j][f] = max(dp[i+1][j][f], dp[i][j][f]);
                    }

                    if (j < k && f) {
                        // Sell -> stop holding, increase transaction count
                        dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][1] + prices[i]);
                        //skip
                        dp[i+1][j][f] = max(dp[i+1][j][f], dp[i][j][f]);
                    }
                    if(j == k){
                        //skip
                        dp[i+1][j][f] = max(dp[i+1][j][f], dp[i][j][f]);
                    }
                }
            }
        }

        // Answer: end at day n, not holding, any j
        int mx = 0;
        for(int i = 0; i<=k; ++i)
            mx = max(mx, dp[n][i][0]);
        return mx;
    }
};


