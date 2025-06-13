auto init = []() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
class Solution {
public:

    bool can(int &mid, vector<int>& A, int &p) {
        int res = 0;
        for(int i = 0; i<A.size()-1; ++i){
            if(A[i+1] - A[i] <= mid) {++res; ++i;}
        }
        return res >= p;
    }

    int minimizeMax(vector<int>& A, int p) {
        if(p == 0) return 0;
        //bs
        sort(A.begin(), A.end());
        int hi = A[A.size()-1], lo = 0, mid, ans = hi;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(can(mid,A,p)){hi = mid-1; ans = mid;}
            else {lo = mid+1;}
        }
        return ans;
    }
};
