#define rep(i,n) for(int i = 0; i<n; ++i)
const int INF = 1e9;
struct SegmentTree {
  int df, n; vector<int> t;
  int mg(int a, int b){ return min(a,b); }
  SegmentTree(vector<int> &A){ df = INF; n = A.size(); t.resize(4*n,df); bld(1,0,n-1,A); }
  void bld(int v, int l, int r, vector<int> &A){
    if(l == r) { t[v] = A[l]; return; }
    int m = (l+r)/2;
    bld(v<<1,l,m,A); bld(v<<1|1,m+1,r,A);
    t[v] = mg(t[v<<1], t[v<<1|1]);
  }
  int qry(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i <= l && j >= r){ if(val != -1) t[v] = val; return t[v]; }
    int m = (l+r)/2;
    int ans = mg(qry(v<<1,l,m,i,j,val), qry(v<<1|1,m+1,r,i,j,val));
    if(val != -1) t[v] = mg(t[v<<1], t[v<<1|1]);
    return ans;
  }
  int qry(int i, int j, int val=-1){ return qry(1,0,n-1,i,j,val); }
};

class Solution {
public:
  int maxDifference(string s, int k) {
    int n = s.size(), ans = -INF;
    rep(da, 5) rep(db, 5) {
      if(da == db) continue;
      vector<int> P_A(n+1), P_B(n+1), D(n+1), parA(n+1), parB(n+1);
      for(int i = 1; i <= n; ++i){
        int d = s[i-1] - '0';
        P_A[i] = P_A[i-1] + (d == da); P_B[i] = P_B[i-1] + (d == db);
        D[i] = P_A[i] - P_B[i];
        parA[i] = P_A[i] & 1; parB[i] = P_B[i] & 1;
      }
      D[0] = parA[0] = parB[0] = 0;
      vector<SegmentTree*> st(4);
      rep(m,4){
        vector<int> arr(n+1, INF);
        rep(i,n+1){
          int mask = (parA[i]<<1) | parB[i];
          if(mask == m) arr[i] = D[i];
        }
        st[m] = new SegmentTree(arr);
      }

      int cur = -INF;
      for(int R = k; R <= n; ++R){
        int high = R - k;
        int limA = P_A[R] - 1, limB = P_B[R] - 1;
        int XA = -1, XB = -1;
        {
          int lo=0, hi=high;
          while(lo<=hi){
            int mid = (lo+hi)/2;
            if(P_A[mid] <= limA){ XA=mid; lo=mid+1; }
            else hi=mid-1;
          }
        }
        {
          int lo=0, hi=high;
          while(lo<=hi){
            int mid = (lo+hi)/2;
            if(P_B[mid] <= limB){ XB=mid; lo=mid+1; }
            else hi=mid-1;
          }
        }
        if(XA < 0 || XB < 0) continue;
        int X = min({high, XA, XB});
        int need = ((1 - (P_A[R]&1))<<1) | (P_B[R]&1);
        int best = st[need]->qry(0,X);
        if(best == INF) continue;
        cur = max(cur, D[R] - best);
      }

      rep(i,4) delete st[i];
      ans = max(ans, cur);
    }
    return ans;
  }
};

