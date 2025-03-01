class Solution {
public:
    int integerBreak(int n) {
        //cauchy-swarts => they have to be equal
        int ans = 0;
        for(int k = 2; k <= n; ++k){
            ans = max(ans, (int)(pow(((n/k)),k-(n%k)) * pow(((n/k)+1),(n%k))));
        }
        return ans;
    }
};
