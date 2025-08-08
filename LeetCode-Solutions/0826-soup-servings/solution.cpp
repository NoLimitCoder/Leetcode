class Solution {
public:


    void add_self (int i, int j, double dp_i_j, vector<vector<double>> &dp, double &ans) {
        if(i >= 0 && j >= 0) dp[i][j] += dp_i_j * 0.25;

        if (i <= 0 && j <= 0) ans += 0.5 * dp_i_j * 0.25;
        else if (i <= 0)      ans += dp_i_j * 0.25;
    };

    double soupServings(int n) {
        if(n > 5000) return 1; if(n == 0) return 0.5;
        vector<vector<double>> dp(n+1, vector<double>(n+1, 0.0));
        dp[n][n] = 1.0;
        double ans = 0.0;
        for (int i = n; i > 0; --i) {
            for (int j = n; j > 0; --j) if(dp[i][j] > 0){
                add_self(i-100, j-0, dp[i][j], dp, ans);
                add_self(i-75, j-25, dp[i][j], dp, ans);
                add_self(i-50, j-50, dp[i][j], dp, ans);
                add_self(i-25, j-75, dp[i][j], dp, ans);
            }
        }
        return ans;
    }
};
