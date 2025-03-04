class Solution {
public:
    int firstBadVersion(int n) {
        int ans = -1;
        int hi = INT_MAX, lo = 0, mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(isBadVersion(mid)){ans = mid; hi = mid-1;}
            else {lo = mid+1;}
        }
        return ans;
    }
};
