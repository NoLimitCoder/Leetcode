typedef long long ll;
const ll MOD = 1e9 + 7;

struct SegmentTree{
  ll df, n; vector<ll> t;
  ll mg(ll a, ll b){return (a*b) % MOD;}
  SegmentTree(vector<ll> A){df=1; n=A.size(); t.resize(4*n,df); bld(1,0,n-1,A);}
  void bld(int v, int l, int r, vector<ll> &A){
    if(l==r) {t[v] = A[l]; return;}
    ll m = (l+r)/2; bld(v<<1,l,m,A); bld(v<<1|1,m+1,r,A);
    t[v] = mg(t[v<<1], t[v<<1|1]);
 }
  ll qry(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i<= l && j>=r){ if(val!=-1) t[v] = val; return t[v];}
    ll m = (l+r)/2, ans = mg(qry(v<<1,l,m,i,j,val), qry(v<<1|1,m+1,r,i,j,val));
    if(val!=-1) t[v] = mg(t[v<<1], t[v<<1|1]);
    return ans;
  } 
  ll qry(int i, int j, int val=-1){return qry(1,0,n-1,i,j,val);}
};

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& Q) {
        vector<ll> P; ll p = 1, i = 0;
        while(p <= n)
            { if(n & (1<<i)) {P.push_back(p);} p *= 2; ++i; }
        SegmentTree st(P);
        vector<int> ans;
        for(auto it : Q){
            int l = it[0], r = it[1];
            ans.push_back(int(st.qry(l,r)%MOD));
        }
        return ans;
    }
};
