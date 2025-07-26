class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        //dp[i][j] -> LCSubarray
        /*transition: if(A[i] == B[j]) ++i, ++j, dp[i+1][j+1]+1
            if(A[i] != B[j]) either go to (i+1, j) (i, j+1) (i+1, j+1) + 0
        */
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n+5, vector<int>(m+5));
        int mx = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(A[i] == B[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
                else {dp[i+1][j+1] = 0;}
                mx = max({mx,dp[i][j],dp[i+1][j+1]});
            }
        }
        return mx;
    }
};
