class Solution {
public:
    int maxNonDecreasingLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<vector<int>> dp(n,vector<int>(2,1));
        //state: dp[i][0] -> at position i I'm taking A[i], dp[i][1] at i I'm taking B[i]
        //transition, dp[i][0] = if cannot come from any A or B i.e. A[i] < A[i-1] && A[i] < B[i-1] = 1
        //else dp[i][0] = max(dp[i-1][0], dp[i-1][1]); the ones you can come from
        int mx = 1;
        for(int i = 1; i<n; ++i){
            //dp[i][0]
            if(A[i] >= A[i-1]) dp[i][0] = max(dp[i][0], dp[i-1][0]+1);
            if(A[i] >= B[i-1]) dp[i][0] = max(dp[i][0], dp[i-1][1]+1);
            //dp[i][1]
            if(B[i] >= A[i-1]) dp[i][1] = max(dp[i][1], dp[i-1][0]+1);
            if(B[i] >= B[i-1]) dp[i][1] = max(dp[i][1], dp[i-1][1]+1);

            mx = max({mx, dp[i][0], dp[i][1]});
        }
        return mx;
    }
};
