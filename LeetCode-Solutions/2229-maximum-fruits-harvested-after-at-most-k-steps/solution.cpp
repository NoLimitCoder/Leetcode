typedef long long ll;
const int MAXN = 5e5;
class Solution {
public:

    ll psum(int l, int r, vector<ll> &P){
        l = max(l, 0); r = min(r, MAXN-1); if (l > r) return 0LL;
        if(l == 0) return P[r];
        return P[r] - P[l-1];
    }

    int maxTotalFruits(vector<vector<int>>& A, int st, int k) {
        int n = A.size();
        vector<ll> P(MAXN, 0);
        for(auto it : A){P[it[0]] = it[1];}
        for(int i = 0; i<MAXN; ++i){if(i) P[i] += P[i-1];}
        ll c3 = 0, c4 = 0, ans = 0;
        for(int i = 0; i<=k; ++i){
            int tk = k-2*i;
            //left
            int l = st - i, r = st + tk;
            c3 = psum(l,r,P);
            //right
            r = st + i; l = st-tk;
            c4 = psum(l,r,P);
            ans = max({ans,c3,c4});
        }
        return ans;
    }
};
