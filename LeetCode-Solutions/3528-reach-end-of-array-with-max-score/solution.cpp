class Solution {
public:
    long long findMaximumScore(vector<int>& A) {
        long long ans = 0, cur = A[0], i = 0;
        for(long long j = 1; j<A.size(); ++j){
            if(A[j] > cur){
                ans += cur * (j-i);
                cur = A[j];
                i = j;
            }
        }
        ans += cur * (A.size()-1-i);
        return ans;
    }
};
