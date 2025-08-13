const int MOD = 1e9+7;
class Solution {
public:
    int numberOfWays(int n, int x) {
        /*
        1. build array of "coins" with all numbers from 1 to y^x st y^x <= n
        2. dp to find number unique combs that sum up to n
        */
        vector<int> coins;
        int tmp = 0, i = 1;
        while(pow(i,x) <= n){coins.push_back(pow(i++,x));}
        vector<int> dp(n+5); dp[0] = 1;
        for(int c : coins){
            //vector<int> ndp = dp;
            for(int sum = n; sum >= 0; --sum) if(sum+c <= n && dp[sum]){
                //ndp[sum + c] += dp[sum]; ndp[sum + c] %= MOD;
                dp[sum + c] += dp[sum]; dp[sum + c] %= MOD;
            }
            //dp = ndp;
        }
        return dp[n];
    }
};
