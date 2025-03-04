class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        A.push_back(-1);
        int idx = -1;
        int hi = A.size()-1, lo = 0, i;
        while(lo<=hi){
            i = (hi+lo)>>1;
            if(A[i] >= A[i+1]){
                hi = i-1;
            }
            else{
                idx = i+1; lo = i+1;
            }
        }
        return idx;
    }
};
