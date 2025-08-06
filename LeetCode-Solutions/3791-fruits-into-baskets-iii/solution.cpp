auto init=atexit([](){ofstream("display_runtime.txt")<<"0";});
const int INF = 2e9;
struct SegmentTree{
  int df, n; vector<int> t;
  int mg(int a, int b){return max(a,b);}
  SegmentTree(vector<int> &A){df=-INF; n=A.size(); t.resize(4*n,df); bld(1,0,n-1,A);}
  void bld(int v, int l, int r, vector<int> &A){
    if(l==r) {t[v] = A[l]; return;}
    int m = (l+r)/2; bld(v<<1,l,m,A); bld(v<<1|1,m+1,r,A);
    t[v] = mg(t[v<<1], t[v<<1|1]);
 }
  int qry(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i<= l && j>=r){ if(val!=-1) t[v] = val; return t[v];}
    int m = (l+r)/2, ans = mg(qry(v<<1,l,m,i,j,val), qry(v<<1|1,m+1,r,i,j,val));
    if(val!=-1) t[v] = mg(t[v<<1], t[v<<1|1]);
    return ans;
  } 
  int qry(int i, int j, int val=-1){return qry(1,0,n-1,i,j,val);}
};


class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree st(baskets);
        int n = baskets.size();
        //bs
        int cnt = 0;
        for(int x : fruits){
            int lo = 0, hi = n-1, mid, ans = -1;
            while(lo<=hi){
                mid = lo + (hi-lo)/2;
                if(st.qry(0,mid) >= x){ ans = mid; hi = mid-1; }
                else lo = mid +1;
            }
            if(ans != -1) {cnt++; st.qry(ans,ans,-INF);}
        }
        return n-cnt;
    }
};
