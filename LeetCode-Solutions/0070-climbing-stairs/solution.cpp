class Solution {
public:

int MEMO[46];

int dp(int n) {
    if(n == 0) return 1;
    if(n< 0) return 0;
    if(MEMO[n] != -1) return MEMO[n];
    return MEMO[n] = dp(n-1) + dp(n-2);
}

    int climbStairs(int n) {
        for(int i = 0; i<46; ++i){
            MEMO[i] = -1;
        }
        return dp(n);
    }
};
