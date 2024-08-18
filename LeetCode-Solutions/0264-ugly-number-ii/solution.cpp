class Solution {
public:
    int nthUglyNumber(int n) {
        int _2 = 0, _3 = 0, _5 = 0;
        vector<int> dp(n); 
        dp[0] = 1;
        for(int i=1; i<n; ++i){
            dp[i] = min({dp[_2]*2, dp[_3]*3, dp[_5]*5});
            if(dp[i] == dp[_2]*2) _2++; 
            if(dp[i] == dp[_3]*3) _3++;
            if(dp[i] == dp[_5]*5) _5++;
        }
        return dp[n-1];
    }
};
