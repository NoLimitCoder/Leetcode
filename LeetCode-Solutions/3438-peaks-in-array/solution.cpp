#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:

struct SegmentTree{
  int df, n; vector<int> t;
  int combine(int a, int b){return a+b;}
  void build(vector<int> A){ 
    df = 0; n = A.size(); while(__builtin_popcount(n)!= 1)n++; t.resize(2*n,df);
    for(int v = 0; v<(int)A.size(); ++v)t[n+v] = A[v];
    for(int v = n-1; v>0; --v) t[v] = combine(t[v<<1],t[v<<1|1]);
  }
  void apply(int v, int l, int r, int val){
    t[v] = (r - l + 1) * val;
  }
  int query(int v, int l, int r, int i, int j, int val){
    if(i > r || j < l) return df;
    if(i <= l && j >= r) { if(val != -1) apply(v, l, r, val); return t[v]; }
    int m = (l+r)/2;
    int ans = combine(query(v<<1, l, m, i, j, val), query(v<<1|1, m+1, r, i, j, val));
    if(val != -1) t[v] = combine(t[v<<1], t[v<<1|1]);
    return ans;
  }
  int query(int i, int j, int val = -1){
    return query(1,0,n-1,i,j,val);
  }
};
    
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); vector<int> ans;
        SegmentTree st; st.build(vector<int>(n,0));
        for(int i = 1; i<n-1; ++i)
            {if(nums[i-1] < nums[i] && nums[i+1] < nums[i]) st.query(i,i,1);}
        for(int q = 0; q<queries.size(); ++q){
            int x = queries[q][0], i = queries[q][1], j = queries[q][2];
            if(x == 1){ ans.push_back(st.query(i+1,j-1)); }
            else{
                nums[i--] = j;
                for(int l=0; l<3; ++l, ++i){
                    if(i>0 && i<n-1){
                        if(nums[i-1] < nums[i] && nums[i+1] < nums[i]) st.query(i,i,1);
                        else st.query(i,i,0);
                    }
                }
            }
        }  
        return ans;
    }
};

