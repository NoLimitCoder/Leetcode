
#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:

    bool valid(char &a, char &b){
        int x = a-'a', y = b-'a';
        if( (x%26 == (y+1)%26) || (y%26 == (x+1)%26) ){
            return 1;
        }
        return 0;
    }

    string mn(string &a, string &b){ return a < b? a : b; }
    
    string lexicographicallySmallestString(string s) {
        int n = s.size(); if (n <= 1) return s;
        vector<vector<int>> adj(n);
        rep(l, n) { for (int k = l + 1; k < n; ++k) { if (valid(s[l], s[k])) { adj[l].push_back(k); } } }
        vector<vector<bool>> rem(n, vector<bool>(n, 0));
        for (int sz = 1; sz <= n; ++sz) {
            for (int l = 0; l + sz - 1 < n; ++l) {
                int r = l + sz - 1;
                for (int k : adj[l]) {
                    if (k > r) break;
                    bool in = (k == l + 1) ? 1 : rem[l+1][k-1], rest = (k == r) ? 1 : rem[k+1][r];
                    if (in && rest) { rem[l][r] = 1; break; }
                }
            }
        }
        vector<vector<string>> dp(n, vector<string>(n));
        rep(i, n) dp[i][i] = string(1, s[i]);
        for (int sz = 2; sz <= n; ++sz) {
            for (int l = 0; l + sz - 1 < n; ++l) {
                int r = l + sz - 1;
                string t = string(1, s[l]) + dp[l+1][r];
                if (t.empty()) {dp[l][r] = t; continue; }
                for (int k : adj[l]) {
                    if (k > r) break;
                    bool in = (k == l + 1) ? 1 : rem[l+1][k-1];
                    if (!in) continue;
                    const string &cand = (k == r ? *(new string("")) : dp[k+1][r]);
                    if (cand < t) { t = cand; if (t.empty()) break; }
                }
                dp[l][r] = t;
            }
        }

        return dp[0][n-1];
    }
};
