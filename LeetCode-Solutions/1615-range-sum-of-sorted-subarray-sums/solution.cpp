auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
const int MOD = 1e9 + 7;
public:
    int rangeSum(vector<int>& A, int n, int l, int r) {
        //1. compute subarray sums
        vector<int> sums;
        for(int i = 0; i<n; ++i){
            int tmp = 0;
            for(int j = i; j<n; ++j){
                tmp += A[j]; tmp %= MOD;
                sums.push_back(tmp);
            }
        }
        //sort sums
        sort(sums.begin(), sums.end());
        //offline RSQ
        n = sums.size();
        vector<int> P(n+1);
        for(int i = 1; i<=n; ++i){
            P[i] += sums[i-1];
            P[i] += P[i-1];
            P[i] %= MOD;
        }
        //O(1)
        return P[r] - P[l-1];
    }
};
