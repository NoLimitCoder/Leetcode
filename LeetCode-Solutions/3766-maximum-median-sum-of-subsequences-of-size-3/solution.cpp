class Solution {
public:
    long long maximumMedianSum(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size(), k = n/3;
        long long s = 0;
        for(int i = 1; i<=k; ++i) s += A[n-2*i];
        return s;
    }
};
