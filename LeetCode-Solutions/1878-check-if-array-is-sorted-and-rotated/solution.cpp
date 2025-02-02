class Solution {
public:
    bool check(vector<int>& A) {
        int flag = 0, n = A.size();
        for(int i = 0; i<n; ++i){ if(A[i] > A[ (i+1)%n ]) flag++; }
        return flag<=1;
    }
};
