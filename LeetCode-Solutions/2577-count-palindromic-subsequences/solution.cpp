const int MOD = 1e9+7;
typedef long long ll;
class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        vector<int> rightCnt(10); vector<vector<int>> rightPair(10, vector<int>(10));
        for (int i = n - 1; i >= 0; --i) {
            int d = s[i] - '0';
            for (int x = 0; x < 10; ++x) { rightPair[d][x] = (rightPair[d][x] + rightCnt[x]) % MOD; }
            rightCnt[d] = (rightCnt[d] + 1) % MOD;
        }
        ll ans = 0;
        vector<int> leftCnt(10); vector<vector<int>> leftPair(10, vector<int>(10));
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            rightCnt[d] = (rightCnt[d] - 1 + MOD) % MOD;
            for (int x = 0; x < 10; ++x) { rightPair[d][x] = (rightPair[d][x] - rightCnt[x] + MOD) % MOD; }
            for (int a = 0; a < 10; ++a)
                for (int b = 0; b < 10; ++b) { ans = (ans + 1LL * leftPair[a][b] * rightPair[b][a]) % MOD; }
            
            for (int x = 0; x < 10; ++x) { leftPair[x][d] = (leftPair[x][d] + leftCnt[x]) % MOD; }
            leftCnt[d] = (leftCnt[d] + 1) % MOD;
        }
        return ans;
    }
};

