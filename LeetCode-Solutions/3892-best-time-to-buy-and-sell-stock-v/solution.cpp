typedef long long ll;
const ll INF = 4e18;
class Solution {
public:
    ll maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(3, -INF)));

        dp[0][0][0] = 0;  // At day 0, 0 transactions, not holding anything

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int s = 0; s < 3; ++s) {
                    if (dp[i][j][s] == -INF) continue;
                    // Skip. valid for every case
                    dp[i+1][j][s] = max(dp[i+1][j][s], dp[i][j][s]);
                    if (s == 0 && j < k) {
                        // Start normal buy
                        dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][0] - prices[i]);
                        // Start short sell
                        dp[i+1][j][2] = max(dp[i+1][j][2], dp[i][j][0] + prices[i]);
                    }
                    if (s == 1 && j < k) {
                        // Finish normal transaction → sell
                        dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][1] + prices[i]);
                    }
                    if (s == 2 && j < k) {
                        // Finish short transaction → buy back
                        dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][2] - prices[i]);
                    }
                }
            }
        }
        ll res = 0;
        for (int j = 0; j <= k; ++j) res = max(res, dp[n][j][0]);
        return res;
    }
};

