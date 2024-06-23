typedef long long ll;
class Solution {
public:
    long long maximumTotalCost(vector<int>& A) {
        int n = A.size();
        long long dp[100006][2] = {};
        //dp[i][0] -> max cost if we don't split here
        //dp[i][1] -> max cost if this is part of 2 
        dp[0][0] = A[0];
        dp[0][1] = -4e18;
        for(int i = 1; i<A.size(); ++i){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1])+A[i];            
            dp[i][1] = dp[i-1][0] - A[i];
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
