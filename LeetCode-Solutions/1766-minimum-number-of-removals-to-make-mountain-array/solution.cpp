auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    int minimumMountainRemovals(vector<int>& A) {
        //LIS
        int n = A.size(), ans = 10001; vector<int> dp, dp2, l(n), r(n);
        for(int i = 0; i<A.size(); ++i){
            //left side
            int pos = (lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin());
            if(pos == dp.size()) dp.push_back(A[i]);
            else dp[pos] = A[i];
            l[i] = dp.size();
            //right side
            pos = (lower_bound(dp2.begin(), dp2.end(), A[n-i-1]) - dp2.begin());
            if(pos == dp2.size()) dp2.push_back(A[n-i-1]);
            else dp2[pos] = A[n-i-1];
            r[n-i-1] = dp2.size();
        }
        for(int i = 0; i<n; ++i) if(l[i] != 1 && r[i] != 1) { ans = min(ans, n-(l[i] + r[i]) +1); }
        return ans;
    }
};
