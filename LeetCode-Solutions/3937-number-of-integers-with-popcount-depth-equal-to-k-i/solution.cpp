typedef long long ll;
#define rep(i,n) for(long long i = 0; i<n; ++i)
#define rep1(i,a,n) for(long long i = a; i<n; ++i)
const int MAXN = 65;
class Solution {
public:
    long long popcountDepth(long long n, int k) {
        ll A[MAXN+5][MAXN+5]; 
        rep(i,MAXN) { A[i][0] = A[i][i] = 1; rep1(j,1,i) A[i][j] = A[i-1][j-1] + A[i-1][j]; }
        ll d[MAXN]; d[1] = 0;
        rep1(i,2,MAXN){ ll p = __builtin_popcountll(i); d[i] = 1 + d[p]; }
        vector<bool> ok(MAXN,0);
        ok[1] = (k==1);
        rep1(t,2,MAXN) if(d[t]+1 == k) ok[t]= 1;
        string tmp = "";
        for(ll t = n; t>0; t>>=1) tmp.push_back('0' + (t&1));
        reverse(tmp.begin(), tmp.end());
        ll ans = 0, ones = 0, L = tmp.size();
        rep(i,L) if(tmp[i]=='1'){
                int rem = L-i-1;
                rep(j, rem+1){
                    ll temp = ones + j;
                    if(temp < MAXN && ok[temp]) ans+= A[rem][j];
                }
                ++ones;
            }
        if(ones < MAXN && ok[ones]) ++ans;
        if(k == 1 && n >= 1) --ans;
        if(k == 0 && n >= 1) ++ans;
        return ans;
    }
};
