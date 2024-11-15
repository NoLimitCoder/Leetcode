auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    
    bool can(int len, int &n, vector<int>& A, vector<int>& P) {
        for(int i = len; i<n-1; ++i){
            int cur = P[i] - P[i-len];
            //invalid to valid
            if(A[i+1] < A[i] && A[i+1] >= A[i-len]){
                if(cur >= P[n-2]-1) return 1;
            }
            //valid to invalid
            else if(A[i+1] >= A[i] && A[i+1] < A[i-len]){
                if(cur >= P[n-2]+1) return 1;
            }
            //invalid to invalid | valid to valid
            else{
                if(cur >= P[n-2]) return 1;
            }
        }
        return 0;
    }

    int findLengthOfShortestSubarray(vector<int>& A) {
        A.insert(A.begin(), 0); A.push_back(2e9); 
        int n = A.size(); vector<int>P(n);
        for(int i = 1; i<n-1; ++i)
            { P[i] += P[i-1]; if(A[i] < A[i-1]) P[i]++; }
        //BS
        int lo = 0, hi = n-1, mid, ans = 0;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(can(mid,n,A,P)){ans = mid; hi = mid-1;}
            else {lo = mid+1;}
        }
        return ans;
    }
};
