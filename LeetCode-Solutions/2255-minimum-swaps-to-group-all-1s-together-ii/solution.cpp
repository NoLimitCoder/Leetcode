auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
#define rep(i,n) for(int i = 0; i<n; ++i)
#define deb(x) cout << #x << ": " << x << '\n'
class Solution {
public:
    int minSwaps(vector<int>& A) {
        int n = A.size(), ans = 0, sz = 0;
        rep(i,n){ sz += A[i]; }
        int i = 0, j = 0, cur = 0;
        while(j<sz){ cur+=A[j++]; }
        ans = cur;
        while(j < n+sz){
            cur -= A[i++%n]; cur += A[j++%n];
            ans = max(ans,cur);
        }
        return sz-ans;
    }
};

