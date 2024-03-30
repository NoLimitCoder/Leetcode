class Solution {
public:
    int change(int sum, vector<int>& coins) {
        long long  dp[sum + 5];
        //dp[i] -> # ways to make sum i with the current coin or more
        for ( int i = 0 ; i <= sum ; ++i ) 
            dp[i] = 0;
        dp[0] = 1;
        for(int i = 0; i < coins.size(); ++i){
            int c = coins[i];
            for(int j = c; j<=sum; ++j){
                dp[j] = dp[j]+ dp[j-c];
            }
            
        }
        return dp[sum];
    }
};
