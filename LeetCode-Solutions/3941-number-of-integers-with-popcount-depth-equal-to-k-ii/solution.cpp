#define rep(i,n) for(int i = 0; i<n; ++i)
typedef long long ll;
struct SegmentTree{
    int df, n; vector<int>t;
    int mg(int a, int b){return a+b;}
    SegmentTree(vector<int>&A){df=0; n=A.size(); t.assign(4*n,df); bld(1,0,n-1,A);}
    void bld(int v, int l, int r, vector<int>&A){
        if(l==r) {t[v] = A[l]; return;}
        int m = (l+r)>>1;
        bld(v<<1,l,m,A);
        bld(v<<1|1,m+1,r,A);
        t[v] = mg(t[v<<1], t[v<<1|1]);
    }
    int qry(int v, int l, int r, int i, int j, int val){
        if(i>r || j<l) return df;
        if(i <= l && r<=j){
            if(val!=-1) t[v] = val; return t[v];
        }
        int m = (l+r)>>1;
        int a = qry(v<<1,l,m,i,j,val);
        int b = qry(v<<1|1,m+1,r,i,j,val);
        if(val!=-1) t[v] = mg(t[v<<1],t[v<<1|1]);
        return mg(a,b);
    }
    int qry(int i, int j, int val = -1){return qry(1,0,n-1,i,j,val);}
};

 ll P(ll x){ 
    ll c = 0; while(x!=1){ x = __builtin_popcountll(x); ++c;} return c;
 }

class Solution {
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& Q) {
        int n = nums.size(); vector<int> d(n);
            rep(i,n) d[i] = P(nums[i]);
                vector<SegmentTree> st;
                rep(k,6){
                    vector<int> A(n);
                    rep(i,n) if(d[i]==k) A[i]=1;
                    st.emplace_back(A);
                }
                vector<int> ans;
                for(auto q : Q){
                    if(q.size() == 4){
                        int l = q[1], r = q[2], k = q[3];
                        ans.push_back(st[k].qry(l,r));
                    }
                    else{
                        int i = q[1];
                        ll v = q[2];
                        int od = d[i], nd = P(v);
                        if(od!=nd){
                            st[od].qry(i,i,0);
                            st[nd].qry(i,i,1);
                            d[i] = nd;
                        }
                    }
                }
        return ans;
    }
};
