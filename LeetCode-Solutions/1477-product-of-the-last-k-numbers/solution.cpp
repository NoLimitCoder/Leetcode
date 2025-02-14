#pragma GCC optimize(O3,"unroll-loops")
auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
const int MAXN = 5e4;

struct SegmentTree{
  int df, n; vector<int> t;
  int mg(int a, int b){return a*b;}
  SegmentTree(){}
  SegmentTree(vector<int> A){df=1; n=A.size(); t.resize(4*n,df); build(1,0,n-1,A);}
  void build(int v, int l, int r, vector<int> &A){
    if(l==r) {t[v] = A[l]; return;}
    int m = (l+r)/2; build(v<<1,l,m,A); build(v<<1|1,m+1,r,A);
    t[v] = mg(t[v<<1], t[v<<1|1]);
 }
  int query(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i<= l && j>=r){ if(val!=-1) t[v] = val; return t[v];}
    int m = (l+r)/2, ans = mg(query(v<<1,l,m,i,j,val), query(v<<1|1,m+1,r,i,j,val));
    if(val!=-1) t[v] = mg(t[v<<1], t[v<<1|1]);
    return ans;
  } 
  int query(int i, int j, int val=-1){return query(1,0,n-1,i,j,val);}
};

class ProductOfNumbers {
public:
    int n; SegmentTree st;
    ProductOfNumbers(){st = SegmentTree(vector<int>(MAXN, 1)); n = 0; }
    void add(int num)     {        st.query(n,n++,num); } 
    int getProduct(int k) { return st.query(n-k,n-1)  ; }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
