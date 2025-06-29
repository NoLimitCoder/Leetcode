#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '
const int MOD = 1e9 + 7;
typedef long long ll;
class Solution {
public:
    int numSubseq(vector<int>& A, int x) {
        int n = A.size();
        vector<ll> pw(n+2);
        pw[0] = 1;
        for(int i = 1; i<=n; ++i){
            pw[i] = 2LL*pw[i-1];
            pw[i] %= MOD;
        }
        sort(A.begin(), A.end());
        long long ans = 0;
        for(int i = 0; i<n; ++i){
            if(x - A[i] < 0) break;
            int pos = upper_bound(A.begin(), A.end(), x-A[i]) - A.begin();
            --pos;
            if(pos < i) continue;
            // it could be wrong
            if(x - A[pos] < 0) {ans++; continue;}
            ans += pw[pos-i]; //subsets of size i pos -1?
            ans %= MOD;
        }
        return (int) ans;
    }
};
