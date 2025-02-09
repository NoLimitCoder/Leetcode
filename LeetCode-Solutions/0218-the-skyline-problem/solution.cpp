auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

struct SegmentTree{
  int df, n; vector<int> t, lz;
  int combine(int a, int b){return max(a,b);}
  SegmentTree(vector<int> A){df = 0; n=A.size(); t.resize(4*n,df); lz.resize(4*n,0); build(1,0,n-1,A);}
  void build(int v, int l, int r, vector<int> &A) {
    if(l==r) {t[v] = A[l]; return;}
    int m = (l+r)/2; build(v<<1,l,m,A); build(v<<1|1,m+1,r,A);
    t[v] = combine(t[v<<1], t[v<<1|1]);
 }
  void apply(int v, int l, int r, int val){ if(l != r) lz[v] = max(lz[v],val); t[v] = max(t[v], val); }
  int  query(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i <= l && j >= r) { if(val != -1) apply(v, l, r, val); return t[v]; }
    int m = (l+r)/2;
    if(lz[v]) { apply(v<<1, l, m, lz[v]); apply(v<<1|1, m+1, r, lz[v]); lz[v] = 0; }
    int ans = combine(query(v<<1, l, m, i, j, val), query(v<<1|1, m+1, r, i, j, val));
    if(val != -1) t[v] = combine(t[v<<1], t[v<<1|1]);
    return ans;
  }
  int query(int i, int j, int val=-1){ return query(1,0,n-1,i,j,val); }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& V) {
        //path compression
        map<int,int> mp, mp2; vector<vector<int>> res; int idx = 1, cur = 0;
        for(int i = 0; i<V.size(); ++i){
            mp[V[i][0]] = 1; mp[V[i][0]-1] = 1; if(V[i][0]!= INT_MAX) mp[V[i][0]+1] = 1; 
            mp[V[i][1]] = 1; mp[V[i][1]-1] = 1; if(V[i][1]!= INT_MAX) mp[V[i][1]+1] = 1; 
        } 
        for(auto it : mp) {mp[it.first] = idx; mp2[idx] = it.first; ++idx;}
        for(int i = 0; i<V.size(); ++i) { V[i][0] = mp[V[i][0]]; V[i][1] = mp[V[i][1]]; }
        //driver code
        SegmentTree st(vector<int> (idx,0));
        for(int i = 0; i<V.size(); ++i){ st.query(V[i][0], V[i][1]-1, V[i][2]); }
        for(int i = 1; i<=idx; ++i){
            int x = st.query(i,i);
            if(x != cur){ res.push_back({mp2[i],x}); cur = x; }
        }
        return res;
    }
};
