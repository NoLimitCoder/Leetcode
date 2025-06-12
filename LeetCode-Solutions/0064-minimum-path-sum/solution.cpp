const int INF = 1e6;
class Solution {
public:
    int minPathSum(vector<vector<int>>& G) {
        int m = G.size(), n = G[0].size();
        vector<vector<int>> dp(m, vector<int>(n,INF));
        dp[0][0] = G[0][0];
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(i+1 < m) dp[i+1][j] = min(dp[i+1][j], G[i+1][j] + dp[i][j]);
                if(j+1 < n) dp[i][j+1] = min(dp[i][j+1], G[i][j+1] + dp[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};
