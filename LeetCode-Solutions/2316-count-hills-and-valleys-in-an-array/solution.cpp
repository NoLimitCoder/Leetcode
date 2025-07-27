class Solution {
public:
    int countHillValley(vector<int>& A) {
        int ans = 0, prev = A[0], n = A.size();
        for(int i = 1; i<n-1; ++i){
            if( (A[i] > A[i-1] && A[i] > A[i+1]) || (A[i] < A[i-1] && A[i] < A[i+1])) ++ans;
            if(A[i] == A[i-1]){
                if( (A[i] > prev && A[i] > A[i+1]) || (A[i] < prev && A[i] < A[i+1])) ++ans;
            }
            else prev = A[i-1];
        }
        return ans;
    }
};
