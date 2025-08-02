#define rep(i,n) for(int i = 0; i<n; ++i)
const int INF = 2e9;
class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size(), m = ws.size(), ans = INF;
        vector<int> l(n), r(m);
        rep(i,n) l[i] = ls[i] + ld[i]; rep(i,m) r[i] = ws[i] + wd[i];
        sort(l.begin(), l.end()); sort(r.begin(), r.end());
        rep(j,m){
            auto it = lower_bound(l.begin(), l.end(), ws[j]);
            int cur;
            if(l[0] >= ws[j]) cur = *it;
            else cur = ws[j];
            ans = min(ans, cur+wd[j]);
        }
        rep(i,n){
            int cur;
            if(r[0] > ls[i]) cur = r[0];
            else cur = ls[i];
            ans = min(ans, cur+ld[i]);
        }
        return ans;
    }
};
