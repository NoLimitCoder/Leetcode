class Solution {
public:
    vector<int> getRow(int x) {
    ++x;
    vector<vector<int>>dp(x);
        //base cases
        for(int i = 0; i<x; ++i){
            dp[i] = vector<int>(i+1);
            dp[i][0] = 1; dp[i][i] = 1;
        }
        //dp
        for(int i = 1; i<x; ++i){
            for(int j = 1; j<=i; ++j){
                if(i+1 < x) dp[i+1][j] = dp[i][j] + dp[i][j-1];
            }
        }
        return dp[x-1];
    }
};
