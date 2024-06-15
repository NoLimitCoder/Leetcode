#pragma GCC optimize("O3,unroll-loops")
auto init = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return'c';}();
class Solution {

struct Node{int val, idx;};

struct SegmentTree{
  int df, n; vector<Node> t;
  Node combine(Node a, Node b){ if(a.val > b.val) return a; return b; }
  void build(vector<int> &A){
    df = 0; n = A.size(); while(__builtin_popcount(n)!=1) ++n; t.resize(2*n,{df,-1});
    for(int i = 0; i<A.size(); ++i)t[n+i] = {A[i],i};
    for(int i = n-1; i>0; --i)t[i] = combine(t[i<<1],t[i<<1|1]);
  }
  Node query(int v, int l, int r, int i, int j, int val){
    if(i>r || j<l) return {df,-1};
    if(i<=l && j>=r){ if(val!=-1) t[v] = {val,i}; return t[v];}
    int m = (l+r)/2;
    Node ans = combine(query(v<<1,l,m,i,j,val), query(v<<1|1,m+1,r,i,j,val));
    if(val!=-1) t[v] = combine(t[v<<1], t[v<<1|1]);
    return ans;
  }
  Node query(int i, int j, int v){
    return query(1,0,n-1,i,j,v);
  }
};

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        //sorting profits and capital by capital
        vector<pair<int,int>> A(n);
        for(int i = 0; i<n; ++i){A[i] = {capital[i],profits[i]};} 
        sort(A.begin(), A.end());
        for(int i = 0; i<n; ++i){capital[i] = A[i].first; profits[i] = A[i].second;}
        //main code
        SegmentTree st; st.build(profits);
        k = min(k,n);
        while(k--){
            //finding the range we can use given our current capital
            int p = upper_bound(capital.begin(), capital.end(), w) - capital.begin(); if(p) p--;
            //this means there's no project available with our current capital so we return w
            if(capital[p] > w) return w;
            //find the maximum profit within this range of capital
            auto [val,idx] = st.query(0,p,-1);
            //adding the maximum to our current capital
            w += val;
            //setting the profit of taking this again to 0 so that we don't take it again in the future
            st.query(idx,idx,0);
        }
        return w;
    }
};
