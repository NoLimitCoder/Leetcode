typedef long long ll;
class Solution {
public:
    int uniquePaths(int m, int n) {
        //nCr( n+m-2, min(n-1, m-1) )
        ll res = 1, N = m + n - 2, K = min(m - 1, n - 1);
        for (int i = 1; i <= K; ++i) {
            res = res * (N - K + i) / i;
        }
        return res;
    }
};
