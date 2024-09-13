struct SegmentTree{
  int df, n; vector<int> t, lz;
  int combine(int a, int b){return a^b;}

  SegmentTree(vector<int> A){df = 0; n=A.size(); t.resize(4*n,df); lz.resize(4*n,0); build(1,0,n-1,A);}
  void build(int v, int l, int r, vector<int> &A){
    if(l==r) {t[v] = A[l]; return;}
    int m = (l+r)/2; build(v<<1,l,m,A); build(v<<1|1,m+1,r,A);
    t[v] = combine(t[v<<1], t[v<<1|1]);
 }

	void apply(int v, int l, int r, int val){
		if(l != r) lz[v] = val; //change to += for range adding
		t[v] = (r - l + 1) * val; //change to += for range adding 
	}
	
  int query(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i <= l && j >= r) { if(val != -1) apply(v, l, r, val); return t[v]; } //apply -> update
    int m = (l+r)/2;
    if(lz[v]) { apply(v<<1, l, m, lz[v]); apply(v<<1|1, m+1, r, lz[v]); lz[v] = 0; }
    int ans = combine(query(v<<1, l, m, i, j, val), query(v<<1|1, m+1, r, i, j, val));
    if(val != -1) t[v] = combine(t[v<<1], t[v<<1|1]); //update
    return ans;
  }

  int query(int i, int j, int val=-1){ return query(1,0,n-1,i,j,val); }
};



class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        SegmentTree st(arr);
        vector<int> ans;
        for(auto q : queries){
            ans.push_back(st.query(q[0],q[1]));
        }
        return ans;
    }
};
