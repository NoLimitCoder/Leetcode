const int INF = 1e4 +1;
class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, INF);
        dp[0] = 0;
        for(int i = 0; i<n; ++i){
            for(int j = A[i]; j>=0; --j){
               if(i+j<n) dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        return dp[n-1];
    }
};
