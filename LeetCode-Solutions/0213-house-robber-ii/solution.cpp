class Solution {
public:
    int rob(vector<int>& A) {
        int n = A.size(); vector<int> dp = A;
        int mx = A[0];
        for(int i = 0; i<n-1; ++i){
            for(int j = i+2; j<n-1; ++j){
                dp[j] = max(dp[j], A[j] + dp[i]);
                
            }
            mx = max(mx,dp[i]);
        }
        dp = A;
        for(int i = 1; i<n; ++i){
            for(int j = i+2; j<n; ++j){
                dp[j] = max(dp[j], A[j] + dp[i]);
                
            }
            mx = max(mx,dp[i]);
        }
        return mx;
    }
};
