struct SegmentTree {
    int df, n; vector<int> t;
    int mg(int a, int b) { return a + b; }
    SegmentTree(int _n) {df = 0; n = _n; t.assign(4*n, df);}
    void upd(int v, int l, int r, int pos, int val) {
        if (l == r) { t[v] += val; return; }
        int m = (l + r) >> 1;
        pos <= m? upd(v<<1,   l,   m, pos, val) : upd(v<<1|1, m+1, r, pos, val);
        t[v] = mg(t[v<<1], t[v<<1|1]);
    }
    void pointUpdate(int pos, int val) { upd(1, 0, n-1, pos, val); }
    int qry(int v, int l, int r, int i, int j) {
        if (i > r || j < l) return df;
        if (i <= l && r <= j) return t[v];
        int m = (l + r) >> 1;
        return mg(qry(v<<1,   l,   m, i, j),qry(v<<1|1, m+1, r, i, j));
    }
    int rangeSum(int i, int j) { if (i > j) return df; return qry(1, 0, n-1, i, j); }
    void rangeAdd(int l, int r, int val) { pointUpdate(l, val); if (r + 1 < n) pointUpdate(r+1, -val); }
    int pointQuery(int i) { return rangeSum(0, i); }
};


class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& Qs) {
        int n = nums.size(), q = Qs.size();
        vector<vector<pair<int,int>>> byL(n);
        for (auto &qq : Qs) {
            int l = qq[0], r = qq[1];
            byL[l].push_back({r, l});
        }
        priority_queue<pair<int,int>> pq;
        SegmentTree st(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (auto &pr : byL[i]) { pq.push(pr); }
            while (st.pointQuery(i) < nums[i]) {
                if (pq.empty()) return -1;
                auto [r, l] = pq.top();  pq.pop();
                st.rangeAdd(l, r, +1); ans++;
            }
        }
        return q - ans;
    }
};

