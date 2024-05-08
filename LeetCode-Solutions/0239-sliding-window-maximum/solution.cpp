      // ====================================start of the segment tree=========================================
class Solution {
class STreeMX{        
    int MN=INT_MIN;
    int MX=INT_MAX;
    vector<int> tree;
    int n;
    int getMx(int v, int tl, int tr, int l, int r) {      
        if (tr <tl) return MN;
        if(l>tr || tl>r)    return MN;       // invalid indices tried!
        if (l <= tl && r >= tr) return tree[v];     // the current segment completely belongs to the answer
        
        int tm = (tl + tr) / 2;
        return max(getMx(v*2, tl, tm, l, r)  , getMx(v*2+1, tm+1, tr, l, r));
    }
    void buildTree(vector<int>& a,int tl, int tr,int v=1){
        if(tl>tr) return;
        if(tl==tr){
            tree[v]=a[tl];
            return;
        }

        int mid=(tl+tr)/2;
        buildTree(a,tl,mid,v*2);
        buildTree(a,mid+1,tr,v*2+1);
        tree[v]=max(tree[v*2],tree[v*2+1]);
    }
    void update(int idx,int val,int v,int tl,int tr){
        if(tl>tr) return;
        if(idx<tl || idx>tr)  return;     //not in the current range
        if(tl==tr){
            tree[v]=val;
            return;
        }
        int tmid=(tl+tr)/2;
        update(idx,val,v*2,tl,tmid);
        update(idx,val,v*2+1,tmid+1,tr);
        tree[v]=max(tree[v*2],tree[v*2+1]);
    }
public:
    STreeMX(int sz,vector<int>& vec){
        n=sz;
        tree.assign(sz*4,0);
        buildTree(vec,0,n-1);
    }

    int getMx(int l,int r){
        return getMx(1,0,n-1,l,r);         // call the function!
    }
    void update(int idx,int val){     // v is the new value!
        update(idx,val,1,0,n-1);
    }

};
// ========================================= Segment tree ends here====================================




public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        STreeMX st(n,nums);
        vector<int> ans;
        for(int i = 0; i+k-1<n; ++i){
            ans.push_back(st.getMx(i,i+k-1));
        }
        return ans;
    }
};
