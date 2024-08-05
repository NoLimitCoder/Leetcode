auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();

class Solution {
public:
struct SegmentTree{
  int df, n; vector<int> t, lz;
  int combine(int a, int b){return a+b;}

  void build(vector<int> A){ 
    df = 0; n = 1; while(n < A.size()) n<<=1; t.resize(2*n,df); lz.resize(2*n,-1);
    for(int v = 0; v < A.size(); ++v)t[n+v] = A[v];
    for(int v = n-1; v>0; --v) t[v] = combine(t[v<<1],t[v<<1|1]);
  }
  void apply(int v, int l, int r, int val){
    if(l != r) lz[v] = val;
    t[v] = (r - l + 1) * val; 
  }
	
  int query(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i <= l && j >= r) { if(val != -1) apply(v, l, r, val); return t[v]; }
    int m = (l+r)/2;
    if(lz[v]!=-1) { apply(v<<1, l, m, lz[v]); apply(v<<1|1, m+1, r, lz[v]); lz[v] = -1; }
    int ans = combine(query(v<<1, l, m, i, j, val), query(v<<1|1, m+1, r, i, j, val));
    if(val != -1) t[v] = combine(t[v<<1], t[v<<1|1]);
    return ans;
  }
  int query(int i, int j, int val=-1){ return query(1,0,n-1,i,j,val); }
};

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& Q) {
        vector<int> ans; SegmentTree st; st.build(vector<int>(n,1));
        for(int q = 0; q<Q.size(); ++q){
            int l = Q[q][0], r = Q[q][1];
            st.query(l+1,r-1,0);
            ans.push_back(st.query(0,n-1 -1));
        }
        return ans;
    }
};
