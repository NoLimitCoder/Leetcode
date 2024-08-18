#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        // ai -> money
        //dp[i] -> max energy at i
        //dp[i][0] -> max energy at i staying in A
        //dp[i][1] -> max energy at i staying in B
        //choices take and skip
        int n = A.size();
        long long dp[n+1][2];
        dp[0][0] = A[0];
        dp[0][1] = B[0];
        dp[1][0] = A[0]+A[1];
        dp[1][1] = B[0]+B[1];
        rep(i,n){
            if(i>=2) dp[i][0] = max(dp[i-1][0], dp[i-2][1]) + A[i];
            if(i>=2) dp[i][1] = max(dp[i-1][1], dp[i-2][0]) + B[i];
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
