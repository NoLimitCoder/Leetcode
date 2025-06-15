class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, INT_MIN)));
        dp[0][0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 2; ++j) {
                for (int f = 0; f <= 1; ++f) {
                    if (dp[i][j][f] == INT_MIN) continue; // unreachable
                    if (j < 2 && !f) {
                        // Buy -> become holding, stay in same j
                        dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][0] - prices[i]);
                        //skip
                        dp[i+1][j][f] = max(dp[i+1][j][f], dp[i][j][f]);
                    }

                    if (j < 2 && f) {
                        // Sell -> stop holding, increase transaction count
                        dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][1] + prices[i]);
                        //skip
                        dp[i+1][j][f] = max(dp[i+1][j][f], dp[i][j][f]);
                    }
                    if(j == 2){
                        //skip
                        dp[i+1][j][f] = max(dp[i+1][j][f], dp[i][j][f]);
                    }
                }
            }
        }

        // Answer: end at day n, not holding, any j
        return max({dp[n][0][0], dp[n][1][0], dp[n][2][0]});
    }
};


