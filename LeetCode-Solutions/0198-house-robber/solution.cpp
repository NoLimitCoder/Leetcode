class Solution {
public:
    int rob(vector<int>& A) {
        int n = A.size(); vector<int> dp = A;
        for(int i = 0; i<n; ++i){
            for(int j = i+2; j<n; ++j){
                dp[j] = max(dp[j], A[j] + dp[i]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
