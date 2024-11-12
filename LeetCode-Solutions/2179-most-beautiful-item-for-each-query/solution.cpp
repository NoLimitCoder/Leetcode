auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

struct SegmentTree{
  int df, n; vector<int> t;
  int combine(int a, int b){return max(a,b);}
  void build(vector<int> A){
    df = 0; n = A.size(); while(__builtin_popcount(n) != 1)++n; t.resize(2*n,df);
    for(int i = 0; i<(int)A.size(); ++i) t[n+i] = A[i];
    for(int v = n-1; v>0; --v) t[v] = combine(t[v<<1], t[v<<1|1]);
  }
  int query(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i<= l && j>=r){ if(val!=-1) t[v] = val; return t[v];}
    int m = (l+r)/2;
    int ans = combine(query(v<<1,l,m,i,j,val),query(v<<1|1,m+1,r,i,j,val));
    if(val!=-1) t[v] = combine(t[v<<1], t[v<<1|1]);
    return ans;
  } 
  int query(int i, int j, int val=-1){ return query(1,0,n-1,i,j,val); }
};

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans; map<int,int> mp; 
        //path compression
        for(auto it : items) {mp[it[0]] = 1;} for(auto it : queries) {mp[it] = 1;}
        int idx = 1; for(auto it : mp) mp[it.first] = idx++;
        //code
        SegmentTree st; st.build(vector<int>(idx,0));
        for(auto it : items)
            {st.query(mp[it[0]], mp[it[0]], max(st.query(mp[it[0]],mp[it[0]]),it[1]));}
        for(auto it : queries) 
            {ans.push_back(st.query(0,mp[it]));}
        return ans;
    }
};
