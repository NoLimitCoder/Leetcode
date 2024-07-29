auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:

struct MergeSortTree{
  int df, n; vector<vector<int>> t;

  void merge(vector<int>&c, vector<int> &a, vector<int> &b){
    int i = 0, j = 0;
    while(i<a.size() && j < b.size()) { c.push_back( (a[i] < b[j])?  a[i++] : b[j++] ); }
    while(i<a.size()) c.push_back(a[i++]);          while(j<b.size()) c.push_back(b[j++]);
  }

  MergeSortTree(vector<int> A) {df = 0; n = A.size(); t.resize(4*n); build(1,0,n-1,A); }

  void build(int v, int l, int r, vector<int> &A){
    if(l == r) {t[v] = {A[l]}; return;}
    int m = (l+r)/2; build(v<<1,l,m,A); build(v<<1|1,m+1,r,A);
    merge(t[v], t[v<<1], t[v<<1|1]);
  }

  int query(int v, int l, int r, int i, int j, int k, int cmp){
    if(i > r || j < l) return df;
    if(i<=l && j>=r){
        int pos = 0;
        if(cmp) pos = t[v].size() - (upper_bound(t[v].begin(), t[v].end(), k) - t[v].begin()); //1 = >k
        else pos = lower_bound(t[v].begin(), t[v].end(), k) - t[v].begin(); //0 = <k
        return pos;
    }
    int m = (l+r)/2;
    return query(v<<1,l,m,i,j,k,cmp) + query(v<<1|1,m+1,r,i,j,k,cmp);
  }
  
  int query(int i, int j, int k, int cmp){return query(1,0,n-1,i,j,k, cmp);}

};

    int numTeams(vector<int>& A) {
        MergeSortTree mst(A); int n = A.size(), ans = 0;
        for(int i = 0; i<n; ++i){
            ans += mst.query(0,i-1,A[i],0) * mst.query(i+1,n-1,A[i],1);
            ans += mst.query(0,i-1,A[i],1) * mst.query(i+1,n-1,A[i],0);
        }
        return ans;
    }
};
