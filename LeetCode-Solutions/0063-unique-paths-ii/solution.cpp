class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& G) {
        int m = G.size(), n = G[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(G[i][j] == 1) continue;
                if(i+1 < m) dp[i+1][j] += dp[i][j];
                if(j+1 < n) dp[i][j+1] += dp[i][j];
            }
        }
        return G[m-1][n-1] == 1? 0 : dp[m-1][n-1];
    }
};
