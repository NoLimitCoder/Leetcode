class Solution {
public:
    vector<int> applyOperations(vector<int>& A) {
        int n = A.size(), j = 0; vector<int> ans(n);
        for(int i = 0; i<n-1; ++i){
            if(A[i] == A[i+1]) {A[i]*=2; A[i+1] = 0;}
            if(A[i]) ans[j++] = A[i];
        }
        if(A[n-1]) ans[j++] = A[n-1];
        return ans;
    }
};
