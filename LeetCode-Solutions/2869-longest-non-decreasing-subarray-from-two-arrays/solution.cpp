class Solution {
public:
    int maxNonDecreasingLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        //dp[i][2] lISubarray ending at i choosing array [1] | [2] as current option
        /*
            transition: dp[i][0] can come from dp[i-1][0] | dp[i][1] if A[i] >= A[i-1] | A[i] >= B[i-1]
        */
        int mx = 1;
        vector<vector<int>> dp(n,vector<int>(2));
        for(int i = 0; i<n; ++i){
            //A[i]
            dp[i][0] = max(dp[i][0], 0 + 1);
            if(i-1 >=0 && A[i] >= A[i-1]) dp[i][0] = max(dp[i][0], dp[i-1][0]+1);
            if(i-1 >=0 && A[i] >= B[i-1]) dp[i][0] = max(dp[i][0], dp[i-1][1]+1);
            //B[i]
            dp[i][1] = max(dp[i][1], 0 + 1);
            if(i-1 >=0 && B[i] >= A[i-1]) dp[i][1] = max(dp[i][1], dp[i-1][0]+1);
            if(i-1 >=0 && B[i] >= B[i-1]) dp[i][1] = max(dp[i][1], dp[i-1][1]+1);
            mx = max({mx,dp[i][0],dp[i][1]});
        }
        return mx;
    }
};
