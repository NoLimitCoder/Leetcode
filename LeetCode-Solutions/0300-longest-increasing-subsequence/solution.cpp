class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        vector<int> dp;
        for(int i = 0; i<A.size(); ++i){
            int pos = (lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin());
            if (dp.empty() || pos == dp.size()) dp.push_back(A[i]);
            else dp[pos] = A[i];
        }
        return dp.size();
    }
};
