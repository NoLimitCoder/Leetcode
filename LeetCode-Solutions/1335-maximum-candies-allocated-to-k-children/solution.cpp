auto init = []() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
class Solution {
public:
    bool can(int &mid, vector<int>& A, long long &k) {
        long long cur = 0;
        for(int i = 0; i<A.size(); ++i){
            cur += A[i]/mid;
        }
        return cur >= k;
    }

    int maximumCandies(vector<int>& A, long long &k) {
        int hi = *max_element(A.begin(),A.end()), lo = 1, mid, ans = 0;
        while(lo<=hi){
            mid = (lo+hi)>>1;
            if(can(mid,A,k)){lo = mid+1; ans = mid;}
            else hi = mid-1;
        }
        return ans;
    }
};
