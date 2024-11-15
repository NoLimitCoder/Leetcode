auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:

    bool can(int n, int mid, vector<int>& A) {
        for(int i : A){ n -= ceil( (1.0*i)/(1.0*mid) ); }
        return n >= 0;
    }

    int minimizedMaximum(int n, vector<int>& A) {
        //BS
        int lo = 1, hi = *max_element(A.begin(),A.end()), mid, ans = -1;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(can(n,mid,A)){ans = mid; hi = mid-1;}
            else {lo = mid+1;}
        }
        return ans;
    }
};
