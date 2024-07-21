class Solution {
public:
    int maxOperations(string s) {
        int n = s.size(); vector<int> dp(n);
        for(int i = n-2; i>=0; --i){
            dp[i] = dp[i+1];
            if(s[i] == '1' && s[i+1] == '0') dp[i]++;
        }
        int ans = 0;
        for(int i = 0; i<n; ++i) if(s[i] == '1')ans += dp[i];
        return ans;
    }
};
